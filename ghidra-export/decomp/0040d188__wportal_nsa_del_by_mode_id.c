// func _wportal_nsa_del_by_mode_id @ 0040d188 size=572

undefined4 _wportal_nsa_del_by_mode_id(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  iVar1 = json_object_object_get(param_1,"auth_type");
  if (iVar1 == 0) {
LAB_0040d1dc:
    uVar3 = 0xff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_del_by_mode_id",0x1168);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_0040d1dc;
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixunsdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
  }
  if (g_portal_auth_mode == 1) {
    iVar1 = json_object_object_get(param_1,"vlan_id");
    if (iVar1 != 0) {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        iVar1 = json_object_get_int(iVar1);
        if (iVar1 == 0) {
          iVar1 = 0xfff;
        }
        goto LAB_0040d250;
      }
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
        if (iVar1 == 0) {
          iVar1 = 0xfff;
        }
        goto LAB_0040d250;
      }
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_nsa_del_by_mode_id",0x116d);
    }
    iVar1 = -1;
    goto LAB_0040d250;
  }
  iVar1 = json_object_object_get(param_1,"serv_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
      goto LAB_0040d250;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_0040d250;
    }
  }
  iVar1 = -1;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_nsa_del_by_mode_id",0x1174);
    iVar1 = -1;
  }
LAB_0040d250:
  wportal_db_nsa_del_by_mode_id(iVar1,uVar3,_wportal_nsa_del_cb,0);
  return 0;
}

