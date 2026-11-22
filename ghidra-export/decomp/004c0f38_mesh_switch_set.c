// func mesh_switch_set @ 004c0f38 size=224

undefined4 mesh_switch_set(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    iVar3 = *param_2;
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d enable %d.\n","mesh_switch_set",0x73b,iVar3);
    }
    if (iVar3 == 1) {
      if (1 < *(int *)(param_1 + 0x14) - 2U) {
        return 0;
      }
      if (mesh_debug_switch == '\0') {
        uVar2 = *(undefined2 *)(param_1 + 0x10);
        iVar3 = 1;
      }
      else {
        printf("[MESH_DEBUG]%s()/%d ap(%u) role %d ap mesh witch need  open \n","mesh_switch_set",
               0x742,(uint)*(ushort *)(param_1 + 0x10),*(int *)(param_1 + 0x14));
        iVar3 = 1;
        uVar2 = *(undefined2 *)(param_1 + 0x10);
      }
    }
    else {
      uVar2 = *(undefined2 *)(param_1 + 0x10);
    }
    apmngr_db_ap_mesh_switch_update(uVar2,iVar3);
    uVar1 = 0;
  }
  return uVar1;
}

