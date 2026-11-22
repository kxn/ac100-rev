// func apdb_init_region_code_list @ 0060d264 size=36

undefined4 apdb_init_region_code_list(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = 0;
  do {
    puVar2 = (undefined1 *)(param_1 + iVar1);
    iVar1 = iVar1 + 1;
    *puVar2 = 0xff;
  } while (iVar1 != 0x20);
  return 0;
}

