// func _mesh_cb_child_rd_foreach @ 004bc7c4 size=1

/* WARNING: Type propagation algorithm not settling */

undefined4 _mesh_cb_child_rd_foreach(int param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int iStack_50;
  int aiStack_4c [9];
  
  aiStack_4c[5] = 0;
  aiStack_4c[6] = 0;
  aiStack_4c[7] = 0;
  aiStack_4c[8] = 0;
  aiStack_4c[1] = 0;
  aiStack_4c[2] = 0;
  aiStack_4c[3] = 0;
  aiStack_4c[4] = 0;
  aiStack_4c[0] = 0;
  iStack_50 = 0;
  iVar8 = *(int *)(param_2 + 0x10);
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar7 = *(int *)(param_2 + 4);
  }
  else {
    iVar7 = *(int *)(param_2 + 8);
  }
  iVar1 = rdmngr_db_get_radio_list_by_ap_id
                    (*(undefined2 *)(param_1 + 0xc),aiStack_4c + 5,4,aiStack_4c,aiStack_4c + 1,4,
                     &iStack_50);
  if (iVar1 == -1) {
    uVar4 = 1;
    if (mesh_warning_switch == '\0') {
      return 1;
    }
    uVar3 = (uint)*(ushort *)(param_1 + 0xc);
    __format = "[MESH_WARNING]%s()/%d rdmngr_db_get_radio_list_by_ap_id of %d failed\n";
    uVar2 = 0x16d;
  }
  else {
    iVar1 = aiStack_4c[0];
    if (*(int *)(param_2 + 0xc) != 0) {
      iVar1 = iStack_50;
    }
    iVar6 = *(int *)(param_2 + 0x10);
    if (iVar1 < iVar6) {
      return 0;
    }
    piVar5 = aiStack_4c + 5;
    if (*(int *)(param_2 + 0xc) != 0) {
      piVar5 = aiStack_4c + 1;
    }
    if (iVar8 == iVar7) {
      piVar5 = piVar5 + iVar6;
      while( true ) {
        if (mesh_debug_switch == '\0') {
          pcVar9 = *(code **)(param_2 + 0x14);
        }
        else {
          printf("[MESH_DEBUG]%s()/%d Traversal rf entry of radio id %d\n",
                 "_mesh_cb_child_rd_foreach",0x178,piVar5[0xffffffff]);
          pcVar9 = *(code **)(param_2 + 0x14);
        }
        iVar8 = (*pcVar9)(piVar5[0xffffffff],*(undefined4 *)(param_2 + 0x18));
        if (iVar8 == 2) break;
        if ((iVar8 != 0) && (mesh_err_switch != '\0')) {
          printf("[MESH_ERROR]%s()/%d Handle rf entry of radio id %d failed\n",
                 "_mesh_cb_child_rd_foreach",0x180,piVar5[0xffffffff]);
        }
        iVar6 = iVar6 + 1;
        piVar5 = piVar5 + 1;
        if (iVar1 < iVar6) {
          return 0;
        }
      }
      return 2;
    }
    if (mesh_debug_switch == '\0') {
      iVar8 = *(int *)(param_2 + 0x10);
    }
    else {
      printf("[MESH_DEBUG]%s()/%d Traversal rf entry of radio id %d\n","_mesh_cb_child_rd_foreach",
             0x186,piVar5[iVar6 + -1]);
      iVar8 = *(int *)(param_2 + 0x10);
    }
    iVar8 = (**(code **)(param_2 + 0x14))(piVar5[iVar8 + -1],*(undefined4 *)(param_2 + 0x18));
    if (iVar8 == 2) {
      return 2;
    }
    uVar4 = 0;
    if (iVar8 == 0) {
      return 0;
    }
    if (mesh_err_switch == '\0') {
      return 0;
    }
    __format = "[MESH_ERROR]%s()/%d Handle rf entry of radio id %d failed\n";
    uVar2 = 0x18e;
    uVar3 = piVar5[*(int *)(param_2 + 0x10) + -1];
  }
  printf(__format,"_mesh_cb_child_rd_foreach",uVar2,uVar3);
  return uVar4;
}

