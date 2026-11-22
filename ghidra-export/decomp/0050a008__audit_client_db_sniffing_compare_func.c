// func _audit_client_db_sniffing_compare_func @ 0050a008 size=16

void _audit_client_db_sniffing_compare_func(int param_1,int param_2)

{
  memcmp(*(void **)(param_1 + 0x10),*(void **)(param_2 + 0x10),6);
  return;
}

