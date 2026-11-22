// func cw_priv_ap_update_feature_dump @ 005a967c size=140

undefined4 cw_priv_ap_update_feature_dump(int param_1)

{
  printf("\t\t\tType: (t=%d,l=%d) private ap update feature \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap update feature (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tvalue: %016llx \r\n");
  printf("\t\t\t\tfeature: %llu \r\n");
  return 0;
}

