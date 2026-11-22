// func FUN_004bde50 @ 004bde50 size=632

undefined4
FUN_004bde50(int param_1,int param_2,int param_3,undefined2 param_4,undefined1 param_5,
            ushort param_6,int param_7,undefined1 param_8,int param_9,undefined4 param_10)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 auStack_140 [4];
  int local_13c;
  int local_138;
  int local_134;
  int local_12c;
  int local_128;
  short local_122;
  
  memset(auStack_140,0,0x114);
  if (param_1 == 0) {
    return 1;
  }
  if (param_7 == 0) {
    return 1;
  }
  iVar1 = apdb_get_radio_by_id
                    (*(undefined4 *)(param_7 + 0x40),param_7 + 0x218,param_8,auStack_140,
                     (int)*(char *)(param_1 + 8));
  if (iVar1 != 0) {
    if (mesh_err_switch == '\0') {
      return 1;
    }
    printf("[MESH_ERROR]%s()/%d ap_id:%d, apdb_get_radio_by_id() failed.\n","mesh_set_rd_cfg_to_re",
           0x34d,(uint)*(ushort *)(param_7 + 0x10));
    return 1;
  }
  if (param_9 == 0) goto LAB_004bdfb8;
  uVar2 = (undefined1)param_2;
  if (*(char *)(param_1 + 8) == '\0') {
    if (param_2 == 0xc) {
      if (local_12c == 0) {
        if (local_138 == 0) goto LAB_004be05c;
        *(undefined1 *)(param_1 + 9) = 10;
      }
      else {
        *(undefined1 *)(param_1 + 9) = uVar2;
      }
    }
    else if (param_2 == 10) {
      if (local_138 == 0) {
LAB_004be05c:
        *(undefined1 *)(param_1 + 9) = 6;
      }
      else {
        *(undefined1 *)(param_1 + 9) = uVar2;
      }
    }
    else {
      *(undefined1 *)(param_1 + 9) = uVar2;
    }
  }
  else if (*(char *)(param_1 + 8) == '\x01') {
    if (param_2 == 0xd) {
      if (local_12c == 0) {
        if (local_138 == 0) goto LAB_004be06c;
        *(undefined1 *)(param_1 + 9) = 0xb;
      }
      else {
        *(undefined1 *)(param_1 + 9) = uVar2;
      }
    }
    else if (param_2 == 0xb) {
      if (local_138 == 0) {
LAB_004be06c:
        if (local_13c != 0) goto LAB_004be034;
LAB_004be078:
        *(undefined1 *)(param_1 + 9) = 7;
      }
      else {
        *(undefined1 *)(param_1 + 9) = uVar2;
      }
    }
    else if (param_2 == 9) {
      if (local_13c == 0) goto LAB_004be078;
LAB_004be034:
      *(undefined1 *)(param_1 + 9) = 9;
    }
    else {
      *(undefined1 *)(param_1 + 9) = uVar2;
    }
  }
  uVar2 = (undefined1)param_3;
  if (param_3 == 6) {
    if (local_128 == 0) {
      *(undefined1 *)(param_1 + 10) = 2;
    }
    else {
      *(undefined1 *)(param_1 + 10) = uVar2;
    }
  }
  else if (param_3 == 5) {
    if (local_134 == 0) {
      *(undefined1 *)(param_1 + 10) = 2;
    }
    else {
      *(undefined1 *)(param_1 + 10) = uVar2;
    }
  }
  else {
    *(undefined1 *)(param_1 + 10) = uVar2;
  }
  *(undefined2 *)(param_1 + 0xc) = param_4;
  iVar1 = _uac_rdmngr_check_rd_chnl
                    (*(undefined4 *)(param_7 + 0x40),param_7 + 0x218,param_8,param_1 + 4);
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0xc) = 0xffff;
  }
  *(undefined1 *)(param_1 + 0x19) = param_5;
LAB_004bdfb8:
  if ((int)local_122 < (int)(uint)param_6) {
    *(short *)(param_1 + 0x1a) = local_122;
  }
  else {
    *(ushort *)(param_1 + 0x1a) = param_6;
  }
  rdmngr_db_rd_cfg_changed_by_mesh(param_1,param_10);
  return 0;
}

