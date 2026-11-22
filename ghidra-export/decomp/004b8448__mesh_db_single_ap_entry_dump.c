// func _mesh_db_single_ap_entry_dump @ 004b8448 size=580

void _mesh_db_single_ap_entry_dump(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined *puVar3;
  char *pcVar4;
  int iVar5;
  
  for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
    putchar(9);
  }
  if (*(ushort *)(param_1 + 0xc) == 0xffff) {
    pcVar4 = "(Isolate root node)";
  }
  else {
    pcVar4 = "";
  }
  iVar5 = 0;
  printf("--AP id:  %d%s\n",(uint)*(ushort *)(param_1 + 0xc),pcVar4);
  bVar1 = 0 < param_2;
  while (bVar1) {
    iVar5 = iVar5 + 1;
    putchar(9);
    bVar1 = iVar5 < param_2;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    pcVar4 = "child";
  }
  else {
    pcVar4 = "root";
  }
  iVar5 = 0;
  printf("  Role:   %s\n",pcVar4);
  bVar1 = 0 < param_2;
  while (bVar1) {
    iVar5 = iVar5 + 1;
    putchar(9);
    bVar1 = iVar5 < param_2;
  }
  iVar5 = 0;
  printf("  policy:  %x\n",*(undefined4 *)(param_1 + 0x30));
  bVar1 = 0 < param_2;
  while (bVar1) {
    iVar5 = iVar5 + 1;
    putchar(9);
    bVar1 = iVar5 < param_2;
  }
  iVar5 = 0;
  printf("  policy mask:  %x\n",*(undefined4 *)(param_1 + 0x2c));
  bVar1 = 0 < param_2;
  if (*(int *)(param_1 + 0x10) == 0) {
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < param_2;
    }
    iVar5 = 0;
    printf("  CAP id:   %d\n",(uint)*(ushort *)(param_1 + 0x14));
    bVar1 = 0 < param_2;
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < param_2;
    }
    iVar5 = 0;
    uVar2 = mesh_db_uplink_type_str_get(*(undefined1 *)(param_1 + 0x18));
    printf("  Link type:   %s\n",uVar2);
    bVar1 = 0 < param_2;
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < param_2;
    }
    puVar3 = *(undefined **)(param_1 + 0x1c);
    pcVar4 = "  Estimate Rate:   %d\n";
  }
  else {
    while (bVar1) {
      iVar5 = iVar5 + 1;
      putchar(9);
      bVar1 = iVar5 < param_2;
    }
    if (*(char *)(param_1 + 0x34) == '\0') {
      puVar3 = &DAT_00691368;
      pcVar4 = "  Temparary re roam:   %s\n";
    }
    else {
      puVar3 = &DAT_006a2d4c;
      pcVar4 = "  Temparary re roam:   %s\n";
    }
  }
  printf(pcVar4,puVar3);
  for (iVar5 = FUN_004081b0(param_1 + 0x20); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
    _mesh_db_single_ap_entry_dump(iVar5,param_2 + 1);
  }
  return;
}

