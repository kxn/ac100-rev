// func cw_priv_mesh2_join_type_dump @ 005b5b4c size=144

undefined4 cw_priv_mesh2_join_type_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap mesh2 join type \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap mesh2 join type (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*puVar1);
  printf("\t\t\t\tMesh2 join type: %u ",*puVar1);
  puts("\r");
  return 0;
}

