// func apupd_jcs_callback_ap_group_delete @ 0063f610 size=456

void apupd_jcs_callback_ap_group_delete(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined8 uVar7;
  undefined2 local_820 [1024];
  
  memset(local_820,0,0x800);
  iVar1 = json_object_object_get(param_1,"group_id");
  if (iVar1 == 0) {
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 5) {
    puVar6 = local_820;
    iVar2 = 0;
    while( true ) {
      iVar3 = json_object_array_length(iVar1);
      if ((iVar3 <= iVar2) || (iVar3 = apmngr_db_get_group_max(local_820), iVar3 <= iVar2)) break;
      iVar3 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar3 == 0) {
LAB_0063f760:
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_callback_ap_group_delete",0xdac);
        }
        *puVar6 = 0xffff;
      }
      else {
        iVar4 = json_object_get_type(iVar3);
        if (iVar4 == 3) {
          uVar5 = json_object_get_int(iVar3);
          *puVar6 = uVar5;
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 != 2) goto LAB_0063f760;
          uVar7 = json_object_get_double(iVar3);
          uVar5 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
          *puVar6 = uVar5;
        }
      }
      iVar2 = iVar2 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 4) {
      iVar1 = json_object_object_length(iVar1);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_0063f698;
    }
    iVar2 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
             "apupd_jcs_callback_ap_group_delete",0xdac);
    }
  }
LAB_0063f698:
  apupd_db_remove_group_in_model_hash(local_820,iVar2);
  return;
}

