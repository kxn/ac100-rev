// func _uac_mac_auth_group_jcs_get @ 0044cb40 size=684

void _uac_mac_auth_group_jcs_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined8 uVar8;
  
  iVar1 = json_object_object_get(param_1,"type");
  if (iVar1 == 0) {
    iVar1 = -1;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d %s not found!\n","_uac_mac_auth_group_jcs_get",0x197,"type");
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar2 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) {
        if (jcs_err_switch == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0;
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_mac_auth_group_jcs_get",0x198);
        }
        goto LAB_0044cbb8;
      }
      uVar8 = json_object_get_double(iVar1);
      iVar2 = __fixdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
    }
    iVar1 = 0;
    if (iVar2 == 0) {
      uVar3 = wserv_profile_get_max_wservice();
      piVar4 = (int *)FUN_004082a0(uVar3,4,0x19b);
      if (piVar4 == (int *)0x0) {
        if (macauth_err_switch == 0) {
          return;
        }
        printf("[MACAUTH_ERROR]%s()/%d malloc failed.\n","_uac_mac_auth_group_jcs_get",0x19e);
        return;
      }
      iVar1 = mac_auth_db_get_bind_ssid(piVar4);
      if (iVar1 == 0) {
        iVar2 = json_object_new_array();
        if (iVar2 == 0) {
          iVar1 = -1;
          if (macauth_err_switch != 0) {
            printf("[MACAUTH_ERROR]%s()/%d JSON_ARRAY_CREATE() fail!\n",
                   "_uac_mac_auth_group_jcs_get",0x1a9);
          }
        }
        else {
          piVar6 = piVar4;
          for (uVar7 = 0; uVar5 = wserv_profile_get_max_wservice(), uVar7 < uVar5; uVar7 = uVar7 + 1
              ) {
            if (*piVar6 != -1) {
              uVar3 = json_object_new_int(uVar7);
              json_object_array_add(iVar2,uVar3);
            }
            piVar6 = piVar6 + 1;
          }
          json_object_object_add(param_2,&DAT_00676a24,iVar2);
          iVar1 = 0;
        }
      }
      else {
        if (macauth_err_switch != 0) {
          printf("[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_ssid() failed.\n",
                 "_uac_mac_auth_group_jcs_get",0x1a3);
        }
        iVar1 = -1;
        iVar2 = 0;
      }
      FUN_00407df0(piVar4);
      goto joined_r0x0044cbb8;
    }
  }
LAB_0044cbb8:
  iVar2 = 0;
joined_r0x0044cbb8:
  if ((iVar1 != 0) && (iVar2 != 0)) {
    json_object_put(iVar2);
    return;
  }
  return;
}

