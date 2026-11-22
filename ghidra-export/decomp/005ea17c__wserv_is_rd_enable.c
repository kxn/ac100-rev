// func _wserv_is_rd_enable @ 005ea17c size=32

bool _wserv_is_rd_enable(void)

{
  int iVar1;
  
  iVar1 = rdmngr_db_get_rd_status();
  return iVar1 != 0;
}

