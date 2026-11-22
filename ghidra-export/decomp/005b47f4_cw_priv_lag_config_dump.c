// func cw_priv_lag_config_dump @ 005b47f4 size=256

undefined4 cw_priv_lag_config_dump(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private lag config \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private lag config(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tenable: %u \r\n",(uint)*pbVar1);
  printf("\t\t\t\tlag_mode: %u \r\n",(uint)pbVar1[1]);
  printf("\t\t\t\tlag_phy_num: %u \r\n",(uint)pbVar1[2]);
  if ((pbVar1[2] != 0) && (*(int *)(pbVar1 + 4) != 0)) {
    puts("\t\t\t\tlag_phy_list: \r");
    for (iVar2 = 0; iVar2 < (int)(uint)pbVar1[2]; iVar2 = iVar2 + 1) {
      printf("\t\t\t\t\tlag_phy: %u,binary: ",(uint)*(byte *)(*(int *)(pbVar1 + 4) + iVar2));
      printbinry(*(undefined1 *)(*(int *)(pbVar1 + 4) + iVar2));
    }
  }
  return 0;
}

