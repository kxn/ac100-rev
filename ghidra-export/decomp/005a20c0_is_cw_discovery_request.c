// func is_cw_discovery_request @ 005a20c0 size=96

bool is_cw_discovery_request(char *param_1)

{
  bool bVar2;
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","is_cw_discovery_request",0x3d2,"NULL != buffer"
          );
    bVar2 = false;
  }
  else {
    bVar2 = false;
    if (*param_1 == '\0') {
      iVar1 = cw_control_header_msg_type_get();
      bVar2 = iVar1 == 1;
    }
  }
  return bVar2;
}

