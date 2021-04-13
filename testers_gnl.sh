# CLONE YOUR PROJECT
cd ~
git clone https://github.com/lucaslf02/get_next_line.git get_next_line
cd get_next_line
norminette *.c *.h


# CLONE ALL GITHUB TESTERS
git clone https://github.com/Mazoise/42TESTERS-GNL.git
cd ..
git clone https://github.com/mrjvs/42cursus_gnl_tests.git
git clone https://github.com/charMstr/GNL_lover.git
cd get_next_line
cp get_next_line_utils.c get_next_line.c get_next_line.h ../GNL_lover/copy_in_here_GNL_files
cd ..
git clone https://github.com/Hellio404/Get_Next_Line_Tester.git
cd get_next_line
git clone https://github.com/Tripouille/gnlTester.git
cd ..

# RUN 42TESTERS-GNL
cd get_next_line/GET42TESTERS-GNL
# bash all_test.sh
# cd ..
# cd ..

# RUN 42cursus_gnl_tests
# cd 42cursus_gnl_tests
# make 
# cd ..

# RUN GNL_lover
# cd GNL_lover
# ./GNL_lover.sh
# cd ..

# RUN GET NEXT LINE TESTER
#cd libftTester
# CONFIGURE MAKEFILE MANUALLY: FT_PATH=../libft
# #make
# cd ..

# RUN gnlTester
# cd get_next_line/gnlTester
# make m
# cd ..

# CLEANUP
# rm -rf get_next_line 42cursus_gnl_tests