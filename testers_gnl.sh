# CLONE YOUR PROJECT
cd ~
git clone https://github.com/lucaslf02/get_next_line.git get_next_line
cd get_next_line
norminette *.c *.h


# CLONE ALL GITHUB TESTERS
git clone https://github.com/Mazoise/42TESTERS-GNL.git
cd ..
git clone https://github.com/mrjvs/42cursus_gnl_tests.git

# RUN 42TESTERS-GNL
cd get_next_line/GET42TESTERS-GNL
bash all_test.sh
cd ..
cd ..

# RUN 42cursus_gnl_tests
cd 42cursus_gnl_tests
make 
cd ..

# RUN libft-war-machine
#cd libft-war-machine
#./grademe.sh
#sed -i '' "s/PATH_LIBFT=../PATH_LIBFT=..\/libft/" my_config.sh
#./grademe.sh
#cd ..

# RUN libftTester
#cd libftTester
# CONFIGURE MAKEFILE MANUALLY: FT_PATH=../libft
# #make
# cd ..

# CLEANUP
rm -rf get_next_line 42cursus_gnl_tests