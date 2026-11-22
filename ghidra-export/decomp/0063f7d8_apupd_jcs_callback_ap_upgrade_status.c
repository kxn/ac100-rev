// func apupd_jcs_callback_ap_upgrade_status @ 0063f7d8 size=528

void apupd_jcs_callback_ap_upgrade_status(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  undefined8 uVar8;
  undefined2 local_810 [1014];
  
  memset(local_810,0,0x7e4);
  iVar1 = json_object_object_get(param_1,"entry_ids");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar7 = local_810;
      for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        if (iVar2 == 0x3f2) {
          iVar2 = 0x3f2;
          break;
        }
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar3 == 0) {
LAB_0063f988:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_callback_ap_upgrade_status",0xd95);
          }
          *puVar7 = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            uVar5 = json_object_get_int(iVar3);
            *puVar7 = uVar5;
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_0063f988;
            uVar8 = json_object_get_double(iVar3);
            uVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
            *puVar7 = uVar5;
          }
        }
        puVar7 = puVar7 + 1;
      }
      goto LAB_0063f86c;
    }
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 4) {
      iVar1 = json_object_object_length(iVar1);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_0063f86c;
    }
  }
  iVar2 = 0;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
           "apupd_jcs_callback_ap_upgrade_status",0xd95);
  }
LAB_0063f86c:
  puVar7 = local_810;
  for (iVar1 = 0; iVar1 < iVar2; iVar1 = iVar1 + 1) {
    uVar5 = *puVar7;
    puVar7 = puVar7 + 1;
    iVar3 = apupd_ap_is_upgrading(uVar5);
    uVar6 = 1;
    if (iVar3 != 0) goto LAB_0063f898;
  }
  uVar6 = 0;
LAB_0063f898:
  uVar6 = json_object_new_int(uVar6);
  json_object_object_add(param_2,"ap_upgrade_status",uVar6);
  return;
}

