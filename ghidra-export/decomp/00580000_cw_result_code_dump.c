// func cw_result_code_dump @ 00580000 size=180

undefined4 cw_result_code_dump(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Result Code \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Result Code (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x\r\n",*puVar3);
  uVar2 = *puVar3;
  if (uVar2 < 0x19) {
    printf("\t\t\tResult Code: %s (%d) \r\n",(&PTR_s_Success_006db850)[uVar2]);
    uVar1 = 0;
  }
  else {
    puts("\t\t\tResult Code Type is wrong \r");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

