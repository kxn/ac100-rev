// func _wportal_db_del_aut_to_nginx @ 0042c1c0 size=980

undefined4 _wportal_db_del_aut_to_nginx(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__s;
  size_t sVar4;
  FILE *__s_00;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  int iVar8;
  char local_c0 [20];
  char acStack_ac [132];
  
  local_c0[0] = '\0';
  local_c0[1] = '\0';
  local_c0[2] = '\0';
  local_c0[3] = '\0';
  local_c0[4] = '\0';
  local_c0[5] = '\0';
  local_c0[6] = '\0';
  local_c0[7] = '\0';
  local_c0[8] = '\0';
  local_c0[9] = '\0';
  local_c0[10] = '\0';
  local_c0[0xb] = '\0';
  local_c0[0xc] = '\0';
  local_c0[0xd] = '\0';
  local_c0[0xe] = '\0';
  local_c0[0xf] = '\0';
  local_c0[0x10] = '\0';
  local_c0[0x11] = '\0';
  memset(acStack_ac,0,0x80);
  iVar1 = json_object_new_array();
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n","_wportal_db_del_aut_to_nginx",0xabd);
    }
  }
  else {
    iVar8 = 0;
    pbVar7 = param_1;
    iVar5 = 0;
    while (iVar5 < param_2) {
      snprintf(local_c0,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*pbVar7,(uint)pbVar7[1],
               (uint)pbVar7[2],(uint)pbVar7[3],(uint)pbVar7[4],(uint)pbVar7[5]);
      iVar2 = json_object_new_object();
      if (iVar2 == 0) {
        if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0042c300;
        printf("[WPORTAL_ERR]%s()/%d malloc json obj failed.\n","_wportal_db_del_aut_to_nginx",0xacb
              );
        pbVar7 = pbVar7 + 0xc0;
        iVar5 = iVar5 + 1;
      }
      else {
        iVar8 = iVar8 + 1;
        uVar3 = json_object_new_string(local_c0);
        json_object_object_add(iVar2,"mac",uVar3);
        uVar3 = json_object_new_string(param_1 + 0x94);
        json_object_object_add(iVar2,&DAT_00677c24,uVar3);
        uVar3 = json_object_new_int(6);
        json_object_object_add(iVar2,"terminate_type",uVar3);
        json_object_array_add(iVar1,iVar2);
LAB_0042c300:
        pbVar7 = pbVar7 + 0xc0;
        iVar5 = iVar5 + 1;
      }
    }
    uVar3 = 0;
    if (iVar8 != 0) {
      __s = (char *)json_object_to_json_string_ext(iVar1,0);
      if (__s == (char *)0x0) {
        uVar3 = 0xffffffff;
        if ((wportal_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[WPORTAL_ERR]%s()/%d JSON_STRING_FROM_OBJ fail!\n","_wportal_db_del_aut_to_nginx",
                 0xadc);
        }
      }
      else {
        sVar4 = strlen(__s);
        sprintf(acStack_ac,"%s_%d_%d","/tmp/wportal_authed_list_by_dm",DAT_0075a190,0);
        DAT_0075a190 = DAT_0075a190 + 1;
        __s_00 = fopen(acStack_ac,"w");
        if (__s_00 == (FILE *)0x0) {
          uVar3 = 0xffffffff;
          if ((wportal_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d open get file[%s] fail!\n","_wportal_db_del_aut_to_nginx",
                   0xae7,acStack_ac);
          }
        }
        else {
          sVar4 = fwrite(__s,sVar4,1,__s_00);
          if (sVar4 == 1) {
            fclose(__s_00);
            iVar5 = json_object_new_object();
            uVar6 = json_object_new_int(2);
            json_object_object_add(iVar5,"type",uVar6);
            uVar6 = json_object_new_int(iVar8);
            json_object_object_add(iVar5,"count",uVar6);
            uVar6 = json_object_new_string(acStack_ac);
            json_object_object_add(iVar5,"filename",uVar6);
            wportal_send_to_nginx(iVar5);
            if (iVar5 != 0) {
              json_object_put(iVar5);
            }
          }
          else {
            if ((wportal_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d write result to file fail!\n",
                     "_wportal_db_del_aut_to_nginx",0xaee);
            }
            fclose(__s_00);
            uVar3 = 0xffffffff;
          }
        }
      }
    }
    json_object_put(iVar1);
  }
  return uVar3;
}

