sudo renice -10 $$
sudo chrt -f -p 12 $$
# El $$ es la forma de acceder al PID del proceso actual la opcion -f de chrt es para que se ponga en fifo y -p para que acepte un pid