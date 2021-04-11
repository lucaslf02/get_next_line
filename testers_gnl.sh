# CLONE YOUR PROJECT
cd ~
git clone https://github.com/lucaslf02/get_next_line.git teste
cd teste
mv libft/ ../
cd ../libft
norminette *.c *.h

# CLONE ALL GITHUB TESTERS
cd ..
git clone https://github.com/Mazoise/42TESTERS-GNL.git

# RUN Libftest
#cd Libftest
#./grademe.sh
#./grademe.sh
#cd ..

# RUN libft-unit-test
# cd libft-unit-test
# make f
# cd ..

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
rm -rf libft Libftest libft-unit-test libft-war-machine libftTester teste