// func cw_priv_reset_mask_dump @ 005baecc size=132

undefined4 cw_priv_reset_mask_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private reset mask \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private reset mask (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*puVar1);
  printf("\t\t\t\tmask: 0x%08x \r\n",*puVar1);
  return 0;
}

