// func cw_priv_fit_fat_button_status_dump @ 005b149c size=132

undefined4 cw_priv_fit_fat_button_status_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private fit fat button status \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private fit fat button status (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tvalue: %08x \r\n",*puVar1);
  printf("\t\t\t\tbutton_status: %d \r\n",*puVar1);
  return 0;
}

