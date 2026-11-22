// func cw_priv_adv_rd_para_dump @ 005a2f24 size=932

undefined4 cw_priv_adv_rd_para_dump(int param_1)

{
  ushort uVar1;
  uint uVar2;
  char *pcVar3;
  byte *pbVar4;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private advanced radio parameter \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private advanced radio parameter (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc)
        );
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x... \r\n",(uint)*pbVar4,(uint)pbVar4[1]);
  printf("\t\t\t\tradio id: %d \r\n",(uint)*pbVar4);
  printf("\t\t\t\tradio mode: %d \r\n",(uint)pbVar4[1]);
  printf("\t\t\t\tbandwidth mode: %d \r\n",(uint)pbVar4[2]);
  printf("\t\t\t\tbrd probe: %d \r\n",(uint)pbVar4[3]);
  printf("\t\t\t\tmax user num: %d \r\n",(uint)*(ushort *)(pbVar4 + 4));
  printf("\t\t\t\tantenna: %d \r\n",(uint)pbVar4[6]);
  printf("\t\t\t\tshort gi: %d \r\n",(uint)pbVar4[7]);
  printf("\t\t\t\twmm: %d \r\n",(uint)pbVar4[8]);
  printf("\t\t\t\tchannel state: %d \r\n",(uint)pbVar4[9]);
  printf("\t\t\t\tpower state: %d \r\n",(uint)pbVar4[10]);
  printf("\t\t\t\tscan mode: %d \r\n",(uint)pbVar4[0xb]);
  printf("\t\t\t\tscan type: %d \r\n",(uint)pbVar4[0xc]);
  printf("\t\t\t\tscan interval: %d \r\n",(uint)*(ushort *)(pbVar4 + 0xe));
  printf("\t\t\t\tstation isolation: %d \r\n",(uint)pbVar4[0x10]);
  uVar2 = (uint)*(ushort *)(param_1 + 0xe);
  if (((uVar2 - 0x14 < 2) || (uVar2 == 0x1a)) || (uVar2 == 0x1b)) {
    printf("\t\t\t\trrsirstct: %d \r\n",(uint)pbVar4[0x11]);
    printf("\t\t\t\trstctval: %d \r\n",(int)(char)pbVar4[0x12]);
    printf("\t\t\t\trssikick: %d \r\n",(uint)pbVar4[0x13]);
    printf("\t\t\t\tkickval: %d \r\n",(int)(char)pbVar4[0x14]);
    uVar2 = (uint)*(ushort *)(param_1 + 0xe);
  }
  if ((uVar2 & 1) == 0) {
    uVar1 = *(ushort *)(param_1 + 0xe);
  }
  else {
    printf("\t\t\t\tair time: %d \r\n",(uint)pbVar4[0x15]);
    uVar1 = *(ushort *)(param_1 + 0xe);
  }
  if (0x15 < uVar1) {
    if ((pbVar4[0x16] & 1) == 0) {
      pcVar3 = "disable";
    }
    else {
      pcVar3 = "enable";
    }
    printf("\t\t\t\tDOWNLINK-MU-MIMO %s \r\n",pcVar3);
    if ((int)((uint)pbVar4[0x16] << 0x1e) < 0) {
      pcVar3 = "enable";
    }
    else {
      pcVar3 = "disable";
    }
    printf("\t\t\t\tUPLINK-MU-MIMO %s \r\n",pcVar3);
    if ((int)((uint)pbVar4[0x16] << 0x1d) < 0) {
      pcVar3 = "enable";
    }
    else {
      pcVar3 = "disable";
    }
    printf("\t\t\t\tDOWNLINK-OFDMA %s \r\n",pcVar3);
    if ((int)((uint)pbVar4[0x16] << 0x1c) < 0) {
      pcVar3 = "enable";
    }
    else {
      pcVar3 = "disable";
    }
    printf("\t\t\t\tUPLINK-OFDMA %s \r\n",pcVar3);
    if ((int)((uint)pbVar4[0x16] << 0x1b) < 0) {
      pcVar3 = "enable";
    }
    else {
      pcVar3 = "disable";
    }
    printf("\t\t\t\tTWT %s \r\n",pcVar3);
    uVar2 = (int)(uint)pbVar4[0x16] >> 6 & 1;
    if ((int)((uint)pbVar4[0x16] << 0x1a) < 0) {
      if (uVar2 == 0) {
        pcVar3 = "\t\t\t\tgi mode 3.2us \r";
      }
      else {
        pcVar3 = "\t\t\t\tgi mode isreserved \r";
      }
    }
    else if (uVar2 == 0) {
      pcVar3 = "\t\t\t\tgi mode 0.8us \r";
    }
    else {
      pcVar3 = "\t\t\t\tgi mode 1.6us \r";
    }
    puts(pcVar3);
    if ((int)(uint)pbVar4[0x16] >> 7 == 0) {
      pcVar3 = "disable";
    }
    else {
      pcVar3 = "enable";
    }
    printf("\t\t\t\t6G %s \r\n",pcVar3);
    if ((pbVar4[0x17] & 1) == 0) {
      pcVar3 = "disable";
    }
    else {
      pcVar3 = "enable";
    }
    printf("\t\t\t\t6G PSC %s \r\n",pcVar3);
    if ((int)((uint)pbVar4[0x17] << 0x1e) < 0) {
      pcVar3 = "enable";
    }
    else {
      pcVar3 = "disable";
    }
    printf("\t\t\t\tMLO %s \r\n",pcVar3);
  }
  return 0;
}

