// func rrc_dump @ 0055e860 size=440

void rrc_dump(int param_1)

{
  char *__s;
  
  if (param_1 == 0) {
    __s = "pointer \'this\' is invalid!\r";
  }
  else {
    puts("***************radio rate******************");
    puts("802.11a:\r");
    printf("\tmandatory rate set:");
    rrc_rate_set_dump(param_1 + 4);
    printf("\tsupported rate set:");
    rrc_rate_set_dump(param_1 + 0x44);
    printf("\tmulticast rate:%d\r\n",*(undefined4 *)(param_1 + 0x84));
    puts("802.11b:\r");
    printf("\tmandatory rate set:");
    rrc_rate_set_dump(param_1 + 0x88);
    printf("\tsupported rate set:");
    rrc_rate_set_dump(param_1 + 200);
    printf("\tmulticast rate:%d\r\n",*(undefined4 *)(param_1 + 0x108));
    puts("802.11g:\r");
    printf("\tmandatory rate set:");
    rrc_rate_set_dump(param_1 + 0x10c);
    printf("\tsupported rate set:");
    rrc_rate_set_dump(param_1 + 0x14c);
    printf("\tmulticast rate:%d\r\n",*(undefined4 *)(param_1 + 0x18c));
    puts("802.11n:\r");
    printf("\tmandatory max mcs index:%d\r\n",*(undefined4 *)(param_1 + 400));
    printf("\tsupported max mcs index:%d\r\n",*(undefined4 *)(param_1 + 0x194));
    printf("\tmulticast mcs index:%d\r\n",*(undefined4 *)(param_1 + 0x198));
    puts("802.11ac:\r");
    printf("\tmandatory max mcs set:%d\r\n",*(undefined4 *)(param_1 + 0x19c));
    printf("\tsupported max mcs set:%d\r\n",*(undefined4 *)(param_1 + 0x1a0));
    printf("\tmulticast mcs set:%d\r\n",*(undefined4 *)(param_1 + 0x1a4));
    puts("802.11ax:\r");
    printf("\tmandatory max mcs set:%d\r\n",*(undefined4 *)(param_1 + 0x1a8));
    printf("\tsupported max mcs set:%d\r\n",*(undefined4 *)(param_1 + 0x1ac));
    printf("\tmulticast mcs set:%d\r\n",*(undefined4 *)(param_1 + 0x1b0));
    __s = "*************radio rate end****************";
  }
  puts(__s);
  return;
}

