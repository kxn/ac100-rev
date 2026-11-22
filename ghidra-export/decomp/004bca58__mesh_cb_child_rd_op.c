// func _mesh_cb_child_rd_op @ 004bca58 size=572

/* WARNING: Type propagation algorithm not settling */

undefined4 _mesh_cb_child_rd_op(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_50;
  int local_4c [9];
  
  local_4c[5] = 0;
  local_4c[6] = 0;
  local_4c[7] = 0;
  local_4c[8] = 0;
  local_4c[1] = 0;
  local_4c[2] = 0;
  local_4c[3] = 0;
  local_4c[4] = 0;
  local_4c[0] = 0;
  local_50 = 0;
  iVar7 = *(int *)(param_2 + 0x10);
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar6 = *(int *)(param_2 + 4);
  }
  else {
    iVar6 = *(int *)(param_2 + 8);
  }
  iVar1 = rdmngr_db_get_radio_list_by_ap_id
                    (*(undefined2 *)(param_1 + 0xc),local_4c + 5,4,local_4c,local_4c + 1,4,&local_50
                    );
  if (iVar1 == -1) {
    uVar4 = 1;
    if (mesh_warning_switch != '\0') {
      printf("[MESH_WARNING]%s()/%d rdmngr_db_get_radio_list_by_ap_id of %d failed\n",
             "_mesh_cb_child_rd_op",0x19f,(uint)*(ushort *)(param_1 + 0xc));
    }
  }
  else {
    iVar1 = local_4c[0];
    if (*(int *)(param_2 + 0xc) != 0) {
      iVar1 = local_50;
    }
    iVar3 = *(int *)(param_2 + 0x10);
    uVar4 = 0;
    if (iVar3 <= iVar1) {
      piVar5 = local_4c + 5;
      if (*(int *)(param_2 + 0xc) != 0) {
        piVar5 = local_4c + 1;
      }
      if (iVar7 == iVar6) {
        piVar5 = piVar5 + iVar3;
        do {
          if (mesh_debug_switch == '\0') {
            iVar7 = piVar5[0xffffffff];
          }
          else {
            pcVar2 = "enable";
            if (*(int *)(param_2 + 0x14) == 0) {
              pcVar2 = "disable";
            }
            printf("[MESH_DEBUG]%s()/%d %s rf entry of radio id %d\n","_mesh_cb_child_rd_op",0x1aa,
                   pcVar2,piVar5[0xffffffff]);
            iVar7 = piVar5[0xffffffff];
          }
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 1;
          rdmngr_rf_state_set(iVar7,*(undefined4 *)(param_2 + 0x14),1);
        } while (iVar3 <= iVar1);
        uVar4 = 0;
      }
      else {
        if (mesh_debug_switch == '\0') {
          iVar7 = *(int *)(param_2 + 0x10);
        }
        else {
          if (*(int *)(param_2 + 0x14) == 0) {
            pcVar2 = "disable";
          }
          else {
            pcVar2 = "enable";
          }
          printf("[MESH_DEBUG]%s()/%d %s rf entry of radio id %d\n","_mesh_cb_child_rd_op",0x1b0,
                 pcVar2,piVar5[iVar3 + -1]);
          iVar7 = *(int *)(param_2 + 0x10);
        }
        rdmngr_rf_state_set(piVar5[iVar7 + -1],*(undefined4 *)(param_2 + 0x14),1);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

