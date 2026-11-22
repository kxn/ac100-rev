// func _uac_mac_auth_mac_jcs_del_for_group @ 00450880 size=648

void _uac_mac_auth_mac_jcs_del_for_group(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 local_fc8 [1001];
  
  memset(local_fc8,0,4000);
  iVar1 = json_object_object_get(param_1,"id");
  if (iVar1 == 0) {
    uVar6 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_mac_jcs_del_for_group",0x14d,
             "id");
    }
    goto LAB_00450934;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 5) {
    puVar7 = local_fc8;
    for (iVar2 = 0; iVar4 = json_object_array_length(iVar1), iVar2 < iVar4; iVar2 = iVar2 + 1) {
      if (iVar2 == 1000) {
        iVar2 = 1000;
        break;
      }
      iVar4 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar4 == 0) {
LAB_00450a5c:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_mac_jcs_del_for_group",0x14e);
        }
        *puVar7 = 0xffffffff;
      }
      else {
        iVar5 = json_object_get_type(iVar4);
        if (iVar5 == 3) {
          uVar6 = json_object_get_int(iVar4);
          *puVar7 = uVar6;
        }
        else {
          iVar5 = json_object_get_type();
          if (iVar5 != 2) goto LAB_00450a5c;
          uVar8 = json_object_get_double(iVar4);
          uVar6 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
          *puVar7 = uVar6;
        }
      }
      puVar7 = puVar7 + 1;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 4) {
      iVar1 = json_object_object_length(iVar1);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_00450910;
    }
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "_uac_mac_auth_mac_jcs_del_for_group",0x14e);
    }
  }
LAB_00450910:
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_mac_jcs_del_for_group() begin, remove num: %d.\n",
           "_uac_mac_auth_mac_jcs_del_for_group",0x150,iVar2);
  }
  uVar6 = 0;
  mac_auth_db_mac_entry_del_in_group(local_fc8,iVar2);
  _uac_mac_auth_sta_check_trigger();
LAB_00450934:
  uVar3 = json_object_new_int(uVar6);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_mac_jcs_del_for_group() finish, id=%d.\n",
           "_uac_mac_auth_mac_jcs_del_for_group",0x157,uVar6);
  }
  return;
}

