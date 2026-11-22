// func cw_priv_bluetooth_config_dump @ 005abeac size=140

undefined4 cw_priv_bluetooth_config_dump(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) private bluetooth config \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: private bluetooth config (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  if (*pbVar2 == 0) {
    pcVar1 = "disable";
  }
  else {
    pcVar1 = "enable";
  }
  printf("\t\t\t\tbluetooth switch: %d(%s)... \r\n",(uint)*pbVar2,pcVar1);
  return 0;
}

