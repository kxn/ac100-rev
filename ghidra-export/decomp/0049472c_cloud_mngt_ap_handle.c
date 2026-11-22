// func cloud_mngt_ap_handle @ 0049472c size=1248

void cloud_mngt_ap_handle(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *__s;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_5e8;
  undefined4 local_5e4;
  undefined4 local_5e0;
  undefined1 auStack_5d8 [536];
  undefined1 auStack_3c0 [192];
  undefined1 auStack_300 [68];
  ushort local_2bc;
  ushort local_2ba;
  char acStack_2b2 [442];
  ushort local_f8;
  ushort local_f6;
  ushort local_f4;
  uint local_f0;
  undefined4 local_ec;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_54;
  
  memset(auStack_300,0,0x2d8);
  memset(auStack_5d8,0,0x2d8);
  local_5e8 = 0;
  local_5e4 = 0;
  local_5e0 = 0;
  if (param_1 == 0) {
    return;
  }
  iVar1 = json_object_new_object();
  iVar2 = FUN_004081b0(param_1);
  iVar8 = 0;
  iVar6 = 0;
  iVar5 = 0;
  iVar7 = 0;
  if (iVar2 != 0) {
    piVar4 = *(int **)(iVar2 + 0xc);
    do {
      if (piVar4 != (int *)0x0) {
        if ((*piVar4 == 1) || (*piVar4 == 5)) {
          if (iVar7 == 0) {
            iVar7 = json_object_new_array();
            FUN_0051ad88(&local_5e8);
            iVar8 = FUN_004080a0(_cloud_mngt_model_data_obj,_cloud_mngt_model_data_key,
                                 _cloud_mngt_model_data_cmp,600);
            if (iVar8 != 0) goto LAB_00494974;
LAB_00494b54:
            iVar3 = 0;
            goto LAB_004948a8;
          }
LAB_00494974:
          iVar3 = apmngr_db_entry_get_by_mac((int)piVar4 + 0x16,auStack_300);
          if (iVar3 == 0) {
            if (local_54 == 0) {
              iVar3 = piVar4[7];
            }
            else {
              snprintf((char *)(piVar4[7] + 0x13e),0x33,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
                       (uint)local_f8,(uint)local_f6,(uint)local_f4,local_f0 >> 0x10,
                       (local_f0 << 0x10) >> 0x18,local_f0 & 0xff,local_ec);
              iVar3 = piVar4[7];
            }
            strncpy((char *)(iVar3 + 8),acStack_2b2,0x9b);
            iVar3 = 1;
            if (local_54 - 1U < 3) {
              iVar3 = (int)"cloud_mngt_apmngr_callback_wtp_join"[local_54 + 0x23];
            }
            *(int *)(piVar4[7] + 0x17c) = iVar3;
            FUN_00408190(local_94,local_90,local_8c,local_88,local_84,piVar4[7] + 0xa4,0x28,
                         "0.0.0.0");
            if ((uint)local_2bc + (uint)local_2ba != 0) {
              snprintf((char *)(piVar4[7] + 0x12e),0x10,"%d.%d",(uint)local_2bc,(uint)local_2ba);
            }
          }
          cloud_mngt_ap_object_add(iVar7,piVar4,1);
          iVar3 = FUN_00407fa0(iVar8,piVar4[7] + 0x178);
          if (iVar3 == 0) {
            __s = (void *)FUN_00408450(0x10,0x859);
            if (__s == (void *)0x0) goto LAB_00494b54;
            iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)piVar4[7],auStack_5d8);
            if (iVar3 == -1) {
              iVar3 = 0;
              if (cloud_mngt_err_switch != '\0') {
                printf("[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n",
                       "cloud_mngt_ap_handle",0x860);
              }
              goto LAB_004948a8;
            }
            memset(__s,0,0x10);
            *(undefined4 *)((int)__s + 0xc) = *(undefined4 *)(piVar4[7] + 0x178);
            FUN_00408380(iVar8,__s);
            FUN_004086b0(&local_5e8,__s);
            iVar3 = cloud_mngt_get_ap_model_obj_by_id
                              (*(undefined4 *)(piVar4[7] + 0x178),auStack_3c0);
            if (iVar3 == 0) goto LAB_004947dc;
            if ((iVar6 == 0) && (iVar6 = json_object_new_array(), iVar6 == 0)) goto LAB_004948a8;
            json_object_array_add(iVar6,iVar3);
            iVar3 = *piVar4;
          }
          else {
            iVar3 = *piVar4;
          }
        }
        else {
LAB_004947dc:
          iVar3 = *piVar4;
        }
        if ((iVar3 == 3) || (iVar3 == 5)) {
          if (iVar5 == 0) {
            iVar5 = json_object_new_array();
          }
          cloud_mngt_ap_object_add(iVar5,piVar4,0);
        }
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      piVar4 = *(int **)(iVar2 + 0xc);
    } while( true );
  }
  if (iVar5 == 0) {
LAB_00494840:
    if (iVar7 != 0) {
      FUN_0049164c(iVar1);
      json_object_object_add(iVar1,"aps",iVar7);
      if ((cloud_mngt_apdb_report_switch != '\0') && (iVar6 != 0)) {
        json_object_object_add(iVar1,&DAT_00699510,iVar6);
        iVar6 = 0;
      }
      iVar3 = 0;
      iVar5 = 0;
      iVar7 = 0;
      cloud_mngt_obj_send_to_cloud(3,iVar1);
      goto LAB_004948a8;
    }
  }
  else {
    FUN_0049164c(iVar1);
    json_object_object_add(iVar1,"aps",iVar5);
    iVar2 = cloud_mngt_obj_send_to_cloud(4,iVar1);
    if (iVar2 == 0) goto LAB_00494840;
  }
  iVar3 = 0;
  iVar5 = 0;
LAB_004948a8:
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (iVar5 != 0) {
    json_object_put(iVar5);
  }
  if (iVar7 != 0) {
    json_object_put(iVar7);
  }
  if (iVar8 != 0) {
    while (iVar1 = FUN_004081b0(&local_5e8), iVar1 != 0) {
      FUN_00407f40(iVar8,iVar1);
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    FUN_00408310();
  }
  if (iVar6 != 0) {
    json_object_put(iVar6);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  return;
}

