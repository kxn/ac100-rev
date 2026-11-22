// func cw_initiate_download_dump @ 005776a0 size=88

undefined4 cw_initiate_download_dump(int param_1)

{
  printf("\t\tType: (t=%d,l=%d) Initiate Download \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Initiate Download (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  return 0;
}

