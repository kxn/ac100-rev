// func cw_priv_image_update_result_dump @ 005b3d0c size=200

undefined4 cw_priv_image_update_result_dump(int param_1)

{
  char *__format;
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private image update result \r\n",(uint)*(ushort *)(param_1 + 0xc)
         ,(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private image update result (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*piVar1);
  printf("\t\t\t\timage update result: %u",*piVar1);
  if (*piVar1 == 0) {
    __format = "(success)";
  }
  else if (*piVar1 == 1) {
    __format = "(MD5 fail)";
  }
  else {
    __format = "(unknown result)";
  }
  printf(__format);
  puts("\r");
  return 0;
}

