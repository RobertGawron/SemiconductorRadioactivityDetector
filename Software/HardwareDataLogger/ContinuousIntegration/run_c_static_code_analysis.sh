cppcheck --enable=all --inline-suppr --force --quiet --error-exitcode=1  ../Software/NUCLEO-F091RC/Inc ../Software/NUCLEO-F091RC/Src 2>C_Lint_ReportFull.txt

# look for errors in gm_* files (those are application files we are interested in)
# store them to separate log ans show them on stdout
grep -F '[../Software/NUCLEO-F091RC/Src/gm_' C_Lint_ReportFull.txt > C_Lint_ReportApplicationOnly.txt 
cat C_Lint_ReportApplicationOnly.txt

# set exit code to ok if no errors were found in application files 
if [ $(cat C_Lint_ReportApplicationOnly.txt | wc -l) -eq 0 ]; then
    true
else
    false
fi