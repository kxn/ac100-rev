// func cloud_mngt_get_ap_model_obj_by_id @ 0048d658 size=1656

int cloud_mngt_get_ap_model_obj_by_id(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  int *piVar13;
  char local_258 [12];
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined1 auStack_23c [36];
  char local_218 [128];
  undefined1 auStack_198 [16];
  int local_188;
  int local_184;
  undefined4 local_180;
  int local_17c;
  int local_178 [10];
  int local_150 [10];
  int local_128;
  int local_124;
  int local_11c;
  int local_118;
  undefined1 auStack_114 [20];
  char local_100 [66];
  char acStack_be [65];
  char local_7d [65];
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  memset(auStack_198,0,0x168);
  local_24c = 0;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  memset(auStack_23c,0,0x21);
  iVar2 = apdb_get_ap_by_id(param_1,param_2,auStack_198);
  iVar10 = 0;
  if (iVar2 == 0) {
    iVar10 = json_object_new_object();
    if (iVar10 == 0) {
      if (cloud_mngt_err_switch != '\0') {
        printf("[CLOUD_MNGT_ERROR]%s()/%d Failed create json obj.\n",
               "cloud_mngt_get_ap_model_obj_by_id",0x4aa);
      }
    }
    else {
      pcVar7 = local_7d;
      if (local_7d[0] == '\0') {
        pcVar7 = acStack_be;
      }
      uVar3 = json_object_new_string(pcVar7);
      json_object_object_add(iVar10,"ap_name",uVar3);
      if (local_100[0] != '\0') {
        uVar3 = json_object_new_string(local_100);
        json_object_object_add(iVar10,"device_type",uVar3);
      }
      uVar3 = json_object_new_int(local_3c);
      json_object_object_add(iVar10,"version",uVar3);
      uVar3 = json_object_new_int64(local_188 >> 0x1f);
      json_object_object_add(iVar10,"id",uVar3);
      uVar3 = json_object_new_int(local_180);
      json_object_object_add(iVar10,"vendor",uVar3);
      if (local_128 != 0) {
        uVar3 = json_object_new_boolean();
        json_object_object_add(iVar10,"support_ap_trunk",uVar3);
      }
      if (local_124 == 1) {
        uVar3 = json_object_new_boolean(1);
        json_object_object_add(iVar10,"support_cloud_upgrade",uVar3);
      }
      if (local_11c == 1) {
        uVar3 = json_object_new_boolean(1);
        json_object_object_add(iVar10,"is_mesh_device",uVar3);
      }
      if (local_118 != 0) {
        uVar3 = json_object_new_int();
        json_object_object_add(iVar10,"product_type",uVar3);
      }
      iVar2 = memcmp(auStack_114,&local_24c,0x10);
      if (iVar2 != 0) {
        FUN_004084f0(auStack_114,0x10,auStack_23c);
        uVar3 = json_object_new_string(auStack_23c);
        json_object_object_add(iVar10,"hardware_id",uVar3);
      }
      if (0 < local_184) {
        uVar3 = json_object_new_int();
        json_object_object_add(iVar10,"ext_wire_phy",uVar3);
      }
      if (local_17c == 1) {
        uVar3 = json_object_new_boolean(1);
        json_object_object_add(iVar10,"is_hd_ap",uVar3);
      }
      bVar1 = false;
      iVar2 = 0;
      do {
        iVar4 = iVar2 + 4;
        if (*(int *)((int)local_178 + iVar2) == 1) {
          bVar1 = true;
        }
        iVar2 = iVar4;
      } while (iVar4 != 0x28);
      if (bVar1) {
        apdb_construct_linked_modify_items(local_178,local_218,0x80);
        uVar3 = json_object_new_string(local_218);
        json_object_object_add(iVar10,"linked_modify_2.4G",uVar3);
      }
      bVar1 = false;
      iVar2 = 0;
      do {
        iVar4 = iVar2 + 4;
        if (*(int *)((int)local_150 + iVar2) == 1) {
          bVar1 = true;
        }
        iVar2 = iVar4;
      } while (iVar4 != 0x28);
      if (bVar1) {
        apdb_construct_linked_modify_items(local_150,local_218,0x80);
        uVar3 = json_object_new_string(local_218);
        json_object_object_add(iVar10,"linked_modify_5.0G",uVar3);
      }
      iVar2 = 0;
      local_30 = json_object_new_array();
      if (local_30 == 0) {
        if (cloud_mngt_err_switch != '\0') {
          printf("[CLOUD_MNGT_ERROR]%s()/%d Failed create array obj.\n",
                 "cloud_mngt_get_ap_model_obj_by_id",0x502);
        }
        json_object_put(iVar10);
        iVar10 = 0;
      }
      else {
        while (iVar2 < local_38) {
          local_218[0] = '\0';
          local_218[1] = '\0';
          local_218[2] = '\0';
          local_218[3] = '\0';
          local_218[4] = '\0';
          local_218[5] = '\0';
          local_218[6] = '\0';
          local_218[7] = '\0';
          local_218[8] = '\0';
          local_218[9] = '\0';
          local_218[10] = 0;
          iVar4 = json_object_new_object();
          if (iVar4 == 0) {
            if (cloud_mngt_err_switch != '\0') {
              printf("[CLOUD_MNGT_ERROR]%s()/%d Failed create json_ptn.\n",
                     "_cloud_mngt_add_model_to_ap",0x47d);
            }
            break;
          }
          psVar11 = (short *)(local_34 + iVar2 * 0x38);
          sprintf(local_218,"%d.%d",(int)*psVar11,(int)psVar11[1]);
          uVar3 = json_object_new_string(local_218);
          json_object_object_add(iVar4,"hwver",uVar3);
          local_258[0] = '\0';
          local_258[1] = '\0';
          local_258[2] = '\0';
          local_258[3] = '\0';
          local_258[4] = '\0';
          local_258[5] = '\0';
          local_258[6] = '\0';
          local_258[7] = '\0';
          local_258[8] = '\0';
          local_258[9] = '\0';
          iVar5 = json_object_new_object();
          if (iVar5 == 0) {
            if (cloud_mngt_err_switch != '\0') {
              printf("[CLOUD_MNGT_ERROR]%s()/%d Failed create json_radio_obj.\n",
                     "_cloud_mngt_add_radios_to_model",0x43b);
            }
LAB_0048da08:
            json_object_put(iVar4);
            iVar2 = iVar2 + 1;
          }
          else {
            iVar12 = 0;
            local_2c = 1;
            iVar6 = 1;
            while (iVar12 < *(int *)(psVar11 + 8)) {
              piVar13 = (int *)(*(int *)(psVar11 + 0x14) + iVar12 * 0x114);
              iVar8 = *piVar13;
              if (iVar8 != 0) {
                if (iVar8 == 1) {
                  iVar8 = iVar6 + 1;
                  sprintf(local_258,"5.0G%d",iVar6);
                  goto LAB_0048d938;
                }
                if (apdb_err_switch != 0) {
                  pcVar7 = "[APDB_ERROR]%s()/line %d : Illegal freq %d.\n";
                  uVar3 = 0x450;
                  goto LAB_0048daa8;
                }
LAB_0048da00:
                json_object_put(iVar5);
                goto LAB_0048da08;
              }
              iVar9 = local_2c + 1;
              sprintf(local_258,"2.4G%d",local_2c);
              iVar8 = iVar6;
              local_2c = iVar9;
LAB_0048d938:
              iVar6 = _cloud_mngt_radio_object_create(piVar13);
              if (iVar6 == 0) {
                if (apdb_err_switch != 0) {
                  iVar8 = *piVar13;
                  pcVar7 = 
                  "[APDB_ERROR]%s()/line %d : _cloud_mngt_radio_object_create failed of freq %d.\n";
                  uVar3 = 0x458;
LAB_0048daa8:
                  printf(pcVar7,"_cloud_mngt_add_radios_to_model",uVar3,iVar8);
                }
                goto LAB_0048da00;
              }
              iVar12 = iVar12 + 1;
              uVar3 = json_object_new_int(iVar12);
              json_object_object_add(iVar6,"radio_index",uVar3);
              json_object_object_add(iVar5,local_258,iVar6);
              iVar6 = iVar8;
            }
            json_object_object_add(iVar4,"radios",iVar5);
            iVar2 = iVar2 + 1;
            json_object_array_add(local_30,iVar4);
          }
        }
        json_object_object_add(iVar10,"models",local_30);
      }
    }
  }
  return iVar10;
}

