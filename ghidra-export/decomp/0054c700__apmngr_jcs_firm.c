// func _apmngr_jcs_firm @ 0054c700 size=636

void _apmngr_jcs_firm(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined8 uVar8;
  char local_c00 [1012];
  undefined2 local_80c [1010];
  
  memset(local_c00,0,0x3f2);
  memset(local_80c,0,0x7e4);
  iVar1 = json_object_new_array();
  if (iVar1 != 0) {
    iVar7 = 0;
    if (((param_1 != 0) && (iVar2 = json_object_get_type(param_1), iVar2 == 5)) &&
       (iVar2 = json_object_array_length(param_1), 0 < iVar2)) {
      iVar2 = json_object_get_type(param_1);
      if (iVar2 == 5) {
        puVar6 = local_80c;
        for (; iVar2 = json_object_array_length(param_1), iVar7 < iVar2; iVar7 = iVar7 + 1) {
          if (iVar7 == 0x3f2) {
            iVar7 = 0x3f2;
            break;
          }
          iVar2 = json_object_array_get_idx(param_1,iVar7);
          if (iVar2 == 0) {
LAB_0054c904:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_apmngr_jcs_firm",0x671);
            }
            *puVar6 = 0xffff;
          }
          else {
            iVar4 = json_object_get_type(iVar2);
            if (iVar4 == 3) {
              uVar5 = json_object_get_int(iVar2);
              *puVar6 = uVar5;
            }
            else {
              iVar4 = json_object_get_type();
              if (iVar4 != 2) goto LAB_0054c904;
              uVar8 = json_object_get_double(iVar2);
              uVar5 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
              *puVar6 = uVar5;
            }
          }
          puVar6 = puVar6 + 1;
        }
      }
      else {
        iVar2 = json_object_get_type(param_1);
        if (((iVar2 != 4) || (iVar2 = json_object_object_length(param_1), iVar2 != 0)) &&
           (iVar7 = 0, jcs_err_switch != 0)) {
          printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n"
                 ,"_apmngr_jcs_firm",0x671);
        }
      }
      apmngr_ap_firm(local_80c,iVar7,local_c00,0);
    }
    puVar6 = local_80c;
    iVar2 = 0;
    while (iVar2 < iVar7) {
      if (local_c00[iVar2] == '\0') {
        uVar5 = *puVar6;
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 1;
        uVar3 = json_object_new_int(uVar5);
        json_object_array_add(iVar1,uVar3);
      }
      else {
        iVar2 = iVar2 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    json_object_object_add(param_2,&DAT_006ce1f8,iVar1);
  }
  return;
}

