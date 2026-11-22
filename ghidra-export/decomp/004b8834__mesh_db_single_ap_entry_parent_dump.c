// func _mesh_db_single_ap_entry_parent_dump @ 004b8834 size=368

undefined4 _mesh_db_single_ap_entry_parent_dump(int param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (param_2 != (int *)0x0) {
    iVar4 = *param_2;
  }
  for (iVar5 = 0; iVar5 < iVar4; iVar5 = iVar5 + 1) {
    putchar(9);
  }
  iVar5 = 0;
  printf("--AP id:  %d\n",(uint)*(ushort *)(param_1 + 0xc));
  bVar1 = 0 < iVar4;
  while (bVar1) {
    iVar5 = iVar5 + 1;
    putchar(9);
    bVar1 = iVar5 < iVar4;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    pcVar3 = "child";
  }
  else {
    pcVar3 = "root";
  }
  iVar5 = 0;
  printf("  Role:   %s\n",pcVar3);
  if (*(int *)(param_1 + 0x10) == 0) {
    bVar1 = 0 < iVar4;
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < iVar4;
    }
    iVar5 = 0;
    printf("  CAP id:   %d\n",(uint)*(ushort *)(param_1 + 0x14));
    bVar1 = 0 < iVar4;
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < iVar4;
    }
    iVar5 = 0;
    uVar2 = mesh_db_uplink_type_str_get(*(undefined1 *)(param_1 + 0x18));
    printf("  Link type:   %s\n",uVar2);
    bVar1 = 0 < iVar4;
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < iVar4;
    }
    printf("  Estimate Rate:   %d\n",*(undefined4 *)(param_1 + 0x1c));
    iVar4 = *param_2;
  }
  else {
    iVar4 = *param_2;
  }
  *param_2 = iVar4 + 1;
  return 0;
}

