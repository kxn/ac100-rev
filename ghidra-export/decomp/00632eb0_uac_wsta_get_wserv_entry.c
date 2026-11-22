// func uac_wsta_get_wserv_entry @ 00632eb0 size=76

void uac_wsta_get_wserv_entry
               (undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = uac_wservice_get_wserv_id(param_1,param_2,param_3);
  if (iVar1 != -1) {
    uac_wservice_get_entry_by_id(iVar1,param_4);
    return;
  }
  return;
}

