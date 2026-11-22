// func _apdb_info_get @ 00551f54 size=1512

undefined4 _apdb_info_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_228;
  undefined2 local_224;
  undefined1 local_222;
  char local_220 [12];
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  char acStack_204 [127];
  undefined1 local_185;
  undefined1 auStack_184 [16];
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 auStack_aa [138];
  short *local_20;
  
  iVar6 = 0;
  memset(acStack_204,0,0x80);
  local_214 = 0;
  local_210 = 0;
  local_20c = 0;
  local_208 = 0;
  local_220[0] = '\0';
  local_220[1] = '\0';
  local_220[2] = '\0';
  local_220[3] = '\0';
  local_220[4] = '\0';
  local_220[5] = '\0';
  local_220[6] = '\0';
  local_220[7] = '\0';
  local_220[8] = '\0';
  local_220[9] = '\0';
  local_220[10] = 0;
  memset(auStack_184,0,0x168);
  local_228 = 0;
  local_224 = 0;
  local_222 = 0;
  memset(auStack_184,0,0x168);
  iVar1 = json_object_object_get(param_1,"model_id");
  if (iVar1 != 0) {
    iVar6 = json_object_get_type(iVar1);
    if (iVar6 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apdb_info_get",0x10f);
      }
      pcVar4 = "";
    }
    strncpy(acStack_204,pcVar4,0x7f);
    local_185 = 0;
    iVar6 = atoi(acStack_204);
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d the model_id is %d\n","_apdb_info_get",0x111,iVar6);
    }
  }
  iVar1 = json_object_object_get(param_1,"firmware_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_apdb_info_get",0x118);
      }
      pcVar4 = "";
    }
    strncpy(acStack_204,pcVar4,0x7f);
    local_185 = 0;
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(&local_214), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d the firmware_id is %s\n","_apdb_info_get",0x119,acStack_204);
    }
    FUN_00408280(&local_214,acStack_204,0x20);
  }
  iVar1 = apdb_get_ap_by_id(iVar6,&local_214,auStack_184);
  if (iVar1 == 0) {
    iVar1 = json_object_new_array();
    if (iVar1 != 0) {
      iVar6 = json_object_new_array();
      if (iVar6 == 0) {
        iVar2 = 0;
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : Failed create json_region_array_obj.\n",
                 "_apdb_info_get",0x12d);
          iVar2 = 0;
        }
      }
      else {
        iVar2 = json_object_new_array();
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) goto LAB_00552258;
          pcVar4 = "[APDB_ERROR]%s()/line %d : Failed create json_radio_array_obj.\n";
          uVar5 = 0x134;
        }
        else {
          sprintf(local_220,"%d.%d",(int)*local_20,(int)local_20[1]);
          uVar5 = json_object_new_string(auStack_aa);
          json_object_object_add(param_2,"model_name",uVar5);
          uVar5 = json_object_new_int(local_174);
          json_object_object_add(param_2,"id",uVar5);
          uVar5 = json_object_new_int(local_170);
          json_object_object_add(param_2,"ext_wire_phy",uVar5);
          uVar5 = json_object_new_int(local_114);
          json_object_object_add(param_2,"support_ap_trunk",uVar5);
          uVar5 = json_object_new_int(local_110);
          json_object_object_add(param_2,"support_cloud_upgrade",uVar5);
          uVar5 = json_object_new_string(local_220);
          json_object_object_add(param_2,"hardware_ver",uVar5);
          uVar5 = json_object_new_int(local_108);
          json_object_object_add(param_2,"is_mesh_device",uVar5);
          iVar3 = apdb_product_type_to_str(&local_228,local_104);
          if (iVar3 != 0) {
            if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d apdb model product type error:%d\n","_apdb_info_get",
                     0x156,local_104);
            }
            goto LAB_00552258;
          }
          uVar5 = json_object_new_string(&local_228);
          json_object_object_add(param_2,"product_type",uVar5);
          iVar3 = apdb_add_port_info_to_ap(iVar1,auStack_184);
          if (iVar3 == 0) {
            iVar3 = apdb_add_region_list_to_ap(iVar6,auStack_184);
            if (iVar3 == 0) {
              iVar3 = add_radios_json_to_model(iVar2,0,auStack_184);
              if (iVar3 == 0) {
                json_object_object_add(param_2,"radios",iVar2);
                json_object_object_add(param_2,"port_info",iVar1);
                json_object_object_add(param_2,"region_list",iVar6);
                return 0;
              }
              if ((apmngr_err_switch == '\0') || (iVar3 = is_target_debug_ap(), iVar3 == 0))
              goto LAB_00552258;
              pcVar4 = "[APMNGR_ERROR]%s()/%d get apdb model failed\n";
              uVar5 = 0x16b;
            }
            else {
              if ((apmngr_err_switch == '\0') || (iVar3 = is_target_debug_ap(), iVar3 == 0))
              goto LAB_00552258;
              pcVar4 = "[APMNGR_ERROR]%s()/%d get apdb model failed\n";
              uVar5 = 0x165;
            }
          }
          else {
            if ((apmngr_err_switch == '\0') || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_00552258;
            pcVar4 = "[APMNGR_ERROR]%s()/%d get apdb model failed\n";
            uVar5 = 0x15f;
          }
        }
        printf(pcVar4,"_apdb_info_get",uVar5);
      }
LAB_00552258:
      json_object_put(iVar1);
      if (iVar6 != 0) {
        json_object_put(iVar6);
      }
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      json_object_put(iVar2);
      return 0xffffffff;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : Failed create json_phy_array_obj.\n";
    uVar5 = 0x126;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[APMNGR_ERROR]%s()/%d get apdb failed\n";
    uVar5 = 0x11f;
  }
  printf(pcVar4,"_apdb_info_get",uVar5);
  return 0xffffffff;
}

