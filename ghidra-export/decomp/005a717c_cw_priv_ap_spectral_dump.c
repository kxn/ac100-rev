// func cw_priv_ap_spectral_dump @ 005a717c size=220

undefined4 cw_priv_ap_spectral_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap spectral \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap spectral (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %02x%02x%02x%02x \r\n",(uint)*pbVar2,(uint)pbVar2[1],(uint)pbVar2[2],
         (uint)pbVar2[3]);
  if (*pbVar2 == 0) {
    pcVar1 = "disable";
  }
  else {
    pcVar1 = "enable";
  }
  printf("\t\t\t\tenable: %d(%s) \r\n ",(uint)*pbVar2,pcVar1);
  printf("\t\t\t\tthreshold: %d \r\n ",(uint)pbVar2[1]);
  printf("\t\t\t\tdiff_threshold: %d \r\n ",(uint)pbVar2[2]);
  printf("\t\t\t\tmax fail num: %d \r\n ",(uint)pbVar2[3]);
  return 0;
}

