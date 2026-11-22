// func rrc_md5_dump @ 0055ea18 size=404

void rrc_md5_dump(undefined4 *param_1)

{
  char *__s;
  
  if (param_1 == (undefined4 *)0x0) {
    __s = "pointer \'this\' is invalid!\r";
  }
  else {
    puts("**************radio rate(md5)**************");
    puts("802.11a(md5):\r");
    printf("\tmandatory rate bitmap:%08x\r\n",*param_1);
    printf("\tsupported rate bitmap:%08x\r\n",param_1[1]);
    printf("\tmulticast rate:%d\r\n",param_1[2]);
    puts("802.11b(md5):\r");
    printf("\tmandatory rate bitmap:%08x\r\n",param_1[3]);
    printf("\tsupported rate bitmap:%08x\r\n",param_1[4]);
    printf("\tmulticast rate:%d\r\n",param_1[5]);
    puts("802.11g(md5):\r");
    printf("\tmandatory rate bitmap:%08x\r\n",param_1[6]);
    printf("\tsupported rate bitmap:%08x\r\n",param_1[7]);
    printf("\tmulticast rate:%d\r\n",param_1[8]);
    puts("802.11n(md5):\r");
    printf("\tmandatory max mcs index:%d\r\n",param_1[9]);
    printf("\tsupported max mcs index:%d\r\n",param_1[10]);
    printf("\tmulticast mcs index:%d\r\n",param_1[0xb]);
    puts("802.11ac(md5):\r");
    printf("\tmandatory max mcs index:%d\r\n",param_1[0xc]);
    printf("\tsupported max mcs index:%d\r\n",param_1[0xd]);
    printf("\tmulticast mcs index:%d\r\n",param_1[0xe]);
    puts("802.11ax(md5):\r");
    printf("\tmandatory max mcs index:%d\r\n",param_1[0xf]);
    printf("\tsupported max mcs index:%d\r\n",param_1[0x10]);
    printf("\tmulticast mcs index:%d\r\n",param_1[0x11]);
    __s = "************radio rate(md5) end************";
  }
  puts(__s);
  return;
}

