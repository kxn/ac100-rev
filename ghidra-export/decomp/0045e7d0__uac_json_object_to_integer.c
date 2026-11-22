// func _uac_json_object_to_integer @ 0045e7d0 size=236

void _uac_json_object_to_integer(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  if ((param_1 != 0) &&
     ((iVar1 = json_object_get_type(), iVar1 == 3 ||
      (iVar1 = json_object_get_type(param_1), iVar1 == 2)))) {
    iVar1 = json_object_get_type(param_1);
    if (iVar1 == 3) {
      uVar2 = json_object_get_int(param_1);
    }
    else {
      iVar1 = json_object_get_type();
      if (iVar1 == 2) {
        uVar3 = json_object_get_double(param_1);
        uVar2 = __fixdfsi((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
      }
      else {
        uVar2 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_json_object_to_integer",0xe1);
        }
      }
    }
  }
  *param_2 = uVar2;
  return;
}

