// func apdb_debug_print_json_in_mem @ 0060e1e0 size=1

void apdb_debug_print_json_in_mem(void)

{
  char *__s;
  
  if ((nego_ap_root != 0) && (__s = (char *)cJSON_Print(), __s != (char *)0x0)) {
    puts(
        "**********************This is json data for negotiation in mem****************************"
        );
    puts(__s);
    puts("*************************************************************************");
    free(__s);
    return;
  }
  puts("Not exist json in mem!!");
  return;
}

