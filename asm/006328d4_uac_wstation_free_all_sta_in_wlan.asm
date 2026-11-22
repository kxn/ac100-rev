; func uac_wstation_free_all_sta_in_wlan @ 0x006328d4 size=0x30
  6328d4:	27bdffd8 	addiu	sp,sp,-40
  6328d8:	30a500ff 	andi	a1,a1,0xff
  6328dc:	30c600ff 	andi	a2,a2,0xff
  6328e0:	10e00003 	beqz	a3,0x6328f0
  6328e4:	afbf0024 	sw	ra,36(sp)
  6328e8:	3c070063 	lui	a3,0x63
  6328ec:	24e70f20 	addiu	a3,a3,3872
  6328f0:	0c18ef86 	jal	0x63be18
  6328f4:	afa00010 	sw	zero,16(sp)
  6328f8:	8fbf0024 	lw	ra,36(sp)
  6328fc:	03e00008 	jr	ra
  632900:	27bd0028 	addiu	sp,sp,40
