pkg load ltfat;
pkg load control;
pkg load signal;

% Signal data is artifically generated, it's not a real signal.
function [signal_time, signal_raw] = load_signal_data ()
    simulation_time_end = 5;  % TODO real values
    sampling_frequency = 200; % TODO real values   
    signal_noise_ratio = 0.8; % TODO real value
    
    dt = 1 / sampling_frequency;
            
    signal_time = (0 : dt : simulation_time_end);
    signal_raw = rot90(noise((simulation_time_end / dt) + 1,'white'));

    % TODO find more realistic impulse function parameters.
    s = tf('s');
    g = -1 / (2*s^2 + 3*s + 4);

    detected_event = signal_noise_ratio .* rot90(impulse(g));
    offset_to_center_pulse = floor( (length(signal_raw) / 2) - (length(detected_event) / 2));
    
    signal_raw(1+ offset_to_center_pulse : length(detected_event)+offset_to_center_pulse) += detected_event;
    
endfunction    


function [] = show_graph ()    
    [signal_time, signal_raw] = load_signal_data();
    
    % Filter signal using 40th order digital filter.
    b = fir1(40, 0.12);
    signal_fir_filter = filter(b, 1, signal_raw);

    # Filter signal using moving averages.
    windowSize = 20;
    signal_moving_mean_filter = filter(ones(1,windowSize)/windowSize,1,signal_fir_filter);
  

    % Enlarge graph window, I didn't find a way to maximalize it.
    figure('position', [0, 0, 1200,900]);
  
    plot(signal_time, signal_raw, 'color',[.8 .8 .8]);
    hold on;
    plot(signal_time, signal_fir_filter, 'color', [1 .0 .0]);
    hold on;
    plot(signal_time, signal_moving_mean_filter, 'color', [.0, .5 .0]);
    
    title('Simulation of digital noise cancelation techniques');
    legend('Raw signal', 'Filtered by FIR', 'Additionaly filtered by moving means');
    xlabel('Time [ms]');
    ylabel('Amplitude [mV]');
    axis([min(signal_time),max(signal_time), min(signal_raw),max(signal_raw)]);
    
endfunction


function [] = main ()
    load_signal_data;
    show_graph;
    
endfunction


main;
