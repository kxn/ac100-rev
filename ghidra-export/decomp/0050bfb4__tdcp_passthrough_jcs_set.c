// func _tdcp_passthrough_jcs_set @ 0050bfb4 size=300

void _tdcp_passthrough_jcs_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__src;
  char acStack_410 [1023];
  undefined1 local_11;
  
  iVar1 = json_object_object_get(param_1,"tdcp_msg");
  memset(acStack_410,0,0x400);
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_tdcp_passthrough_jcs_set",0x711);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_410,__src,0x3ff);
  local_11 = 0;
  if (tdcp_debug_switch != 0) {
    printf("[TDCP_DEBUG]%s()/%d get tdcp_msg :%s\n","_tdcp_passthrough_jcs_set",0x713,acStack_410);
  }
  iVar1 = tdcpRequest(acStack_410);
  if (tdcp_debug_switch != 0) {
    printf("[TDCP_DEBUG]%s()/%d the response is %s\n","_tdcp_passthrough_jcs_set",0x717,iVar1);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return;
}

