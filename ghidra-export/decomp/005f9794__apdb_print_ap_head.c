// func _apdb_print_ap_head @ 005f9794 size=80

void _apdb_print_ap_head(void)

{
  printf("%-10s\t%-16s\t%-16s\t%-5s\t%-16s\t\n","id","ap_name","ap_nickname","vendor",
         "supported hwver");
  return;
}

