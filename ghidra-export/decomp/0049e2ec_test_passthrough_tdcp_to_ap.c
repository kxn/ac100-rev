// func test_passthrough_tdcp_to_ap @ 0049e2ec size=1

void test_passthrough_tdcp_to_ap(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = json_tokener_parse(), iVar1 != 0)) {
    _ac_passthrough_jcs_set(iVar1,0);
    json_object_put(iVar1);
    return;
  }
  return;
}

