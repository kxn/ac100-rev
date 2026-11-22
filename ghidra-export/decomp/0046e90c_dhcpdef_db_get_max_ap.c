// func dhcpdef_db_get_max_ap @ 0046e90c size=44

int dhcpdef_db_get_max_ap(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  return iVar1 + iVar2;
}

