$fn = 50;

// taken from chassis datasheet
wall_thickness = 1.5;
chassis_inner_thickness = 26 - wall_thickness;

// the printed element is a sum of simple boxes
// this is the default thickness of them
mainboard_thickness = 3;

// The dent holds the holder in Z position
// it is placed between bottom and top chassis
// the top chassis has an inner aureola that
// doesn't touch the bottom chassis
// this space is where the dent goes
module upper_dent_3d() {
    // taken from chassis 3d model
    x = chassis_inner_thickness + 0.5;
    y = 30;
    z = 4.5 - 2.5;

    translate([-wall_thickness/2, 0, 0])
    linear_extrude(height = z)
    square([x, y], center = true);
}

// bottom part to make sure PCB stays in place
module bottom_bar_3d() { 
    // taken from chassis datasheet 
    x = mainboard_thickness;
    y = 48;
    z = 10;
    
    translate([chassis_inner_thickness/2 - x/2, 0, 0])
    linear_extrude(height = z)
    square([x, y], center = true);
}

// helper to create a single nut insertion
module insert_nut_wall_2d(x, y, inner_d, outer_d) {
    translate([x, y, 0]) {
        difference() {
            circle(d = outer_d);
            circle(d = inner_d);
        }
    }
}

// four nuts to mount the PCB
module pcb_nuts_holders_3d(x, y, d_in, thickness, z) {
    d_out = d_in + thickness;
    
    linear_extrude(height = z) {
        for (sx = [-1, 1]) {
            for (sy = [-1, 1]) {
                insert_nut_wall_2d(sx*x, sy*y, d_in, d_out);
            }
        }
    }
}

module nuts_cutout_3d(x, y, d_in, z) {
    linear_extrude(height = z) {
        for (sx = [-1, 1]) {
            for (sy = [-1, 1]) {
                translate([sx*x, sy*y, 0]) 
                    circle(d = d_in);
            }
        }
    }
}

// part where all other parts connect to
module mainboard_3d() {
    // taken from chassis datasheet
    linear_extrude(height = mainboard_thickness)
    square([chassis_inner_thickness, 48], center = true);
}

// instantiate all modules
// union not needed but made for FreeCAD export issues
module main_pcb_holder_3d() {
    // X-Y positions taken from kicad model
    // for the auxiliary board
    x = 3.5;
    y = 30.5 / 2;
    
    // Heat Set Insert Nuts diameter from specs
    // 4mm outside, make tight so it stays
    d_in_holder = 4 - 1;
    thickness = 2;
    z_holder = mainboard_thickness + 3;
    z_cutout = mainboard_thickness;
    
    difference() {
        union() {
            mainboard_3d();
            upper_dent_3d();
            bottom_bar_3d();
            pcb_nuts_holders_3d(x, y, d_in_holder, thickness, z_holder);
        }
        nuts_cutout_3d(x, y, d_in_holder, z_cutout);
    }
}

main_pcb_holder_3d();

// DONT FORGET TO ADD FILLETS in FREECAD
// they are important because printed part will
// fit to chassis that already has fillets
// they can't be omitted, parts won't fit!