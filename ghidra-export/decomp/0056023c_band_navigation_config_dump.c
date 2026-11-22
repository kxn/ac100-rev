// func band_navigation_config_dump @ 0056023c size=132

void band_navigation_config_dump(int param_1)

{
  if (param_1 != 0) {
    puts("band navigation configure\r");
    printf("\tmax users allowed to connect an ap:%u\r\n",*(undefined4 *)(param_1 + 8));
    printf("\tmax difference between two ap\'s users:%u\r\n",*(undefined4 *)(param_1 + 0xc));
    printf("\tmax failure times allowed for a client to connect the same ap:%u\r\n",
           *(undefined4 *)(param_1 + 0x10));
    printf("\tstatus:%u\r\n",*(undefined4 *)(param_1 + 4));
    return;
  }
  puts("pointer \'this\' is invalid!\r");
  return;
}

