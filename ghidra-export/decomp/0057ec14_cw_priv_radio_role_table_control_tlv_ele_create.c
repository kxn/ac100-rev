// func cw_priv_radio_role_table_control_tlv_ele_create @ 0057ec14 size=484

undefined1 * cw_priv_radio_role_table_control_tlv_ele_create(uint param_1)

{
  undefined1 *__s;
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  size_t __n;
  int iVar5;
  
  if ((capwap_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("[CW_DEBUG]%32s():%4d enter cw_priv_radio_role_table_control_tlv_ele_init\n",
           "cw_priv_radio_role_table_control_tlv_ele_create",499);
  }
  __n = (param_1 & 0xff) << 3;
  __s = (undefined1 *)FUN_00408450(__n,0x1f7);
  if (__s == (undefined1 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[CW_ERROR]%32s():%4d Malloc tlv ele failed\n",
             "cw_priv_radio_role_table_control_tlv_ele_create",0x1fa);
    }
  }
  else {
    iVar5 = 0;
    memset(__s,0,__n);
    while (iVar5 < (int)(param_1 & 0xff)) {
      if (iVar5 == 0) {
        *__s = 0;
        *(undefined2 *)(__s + 2) = 1;
        puVar1 = (undefined1 *)FUN_00408450(1,0x206);
        *(undefined1 **)(__s + 4) = puVar1;
        if (puVar1 == (undefined1 *)0x0) {
          if (capwap_err_switch == 0) {
            iVar5 = 1;
          }
          else {
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              iVar5 = 1;
            }
            else {
              uVar4 = 0x209;
LAB_0057ed8c:
              iVar5 = iVar5 + 1;
              printf("[CW_ERROR]%32s():%4d Malloc tlv ele failed\n",
                     "cw_priv_radio_role_table_control_tlv_ele_create",uVar4);
            }
          }
        }
        else {
          *puVar1 = 1;
          iVar5 = 1;
        }
      }
      else if (iVar5 == 1) {
        __s[8] = 1;
        *(undefined2 *)(__s + 10) = 4;
        puVar2 = (undefined4 *)FUN_00408450(4,0x211);
        *(undefined4 **)(__s + 0xc) = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          if (capwap_err_switch == 0) {
            iVar5 = 2;
          }
          else {
            iVar3 = is_target_debug_ap();
            if (iVar3 != 0) {
              uVar4 = 0x214;
              goto LAB_0057ed8c;
            }
            iVar5 = 2;
          }
        }
        else {
          iVar5 = 2;
          *puVar2 = 3;
        }
      }
      else {
        iVar5 = iVar5 + 1;
      }
    }
  }
  return __s;
}

