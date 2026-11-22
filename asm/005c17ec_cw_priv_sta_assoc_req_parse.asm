; func cw_priv_sta_assoc_req_parse @ 0x005c17ec size=0x1f4
  5c17ec:	27bdffd8 	addiu	sp,sp,-40
  5c17f0:	afb20020 	sw	s2,32(sp)
  5c17f4:	00a09021 	move	s2,a1
  5c17f8:	afb1001c 	sw	s1,28(sp)
  5c17fc:	24050080 	li	a1,128
  5c1800:	00808821 	move	s1,a0
  5c1804:	afb00018 	sw	s0,24(sp)
  5c1808:	afbf0024 	sw	ra,36(sp)
  5c180c:	0c102114 	jal	0x408450
  5c1810:	24040014 	li	a0,20
  5c1814:	10400029 	beqz	v0,0x5c18bc
  5c1818:	00408021 	move	s0,v0
  5c181c:	00002821 	move	a1,zero
  5c1820:	24060014 	li	a2,20
  5c1824:	0c101cf0 	jal	0x4073c0
  5c1828:	00402021 	move	a0,v0
  5c182c:	0c15c5b0 	jal	0x5716c0
  5c1830:	02202021 	move	a0,s1
  5c1834:	a2020000 	sb	v0,0(s0)
  5c1838:	2c420020 	sltiu	v0,v0,32
  5c183c:	1040004b 	beqz	v0,0x5c196c
  5c1840:	3c020075 	lui	v0,0x75
  5c1844:	0c15c5b0 	jal	0x5716c0
  5c1848:	02202021 	move	a0,s1
  5c184c:	a2020001 	sb	v0,1(s0)
  5c1850:	2c420011 	sltiu	v0,v0,17
  5c1854:	10400055 	beqz	v0,0x5c19ac
  5c1858:	3c020075 	lui	v0,0x75
  5c185c:	26050002 	addiu	a1,s0,2
  5c1860:	24060006 	li	a2,6
  5c1864:	0c15c702 	jal	0x571c08
  5c1868:	02202021 	move	a0,s1
  5c186c:	8e420014 	lw	v0,20(s2)
  5c1870:	8c420000 	lw	v0,0(v0)
  5c1874:	30420040 	andi	v0,v0,0x40
  5c1878:	14400036 	bnez	v0,0x5c1954
  5c187c:	00000000 	nop
  5c1880:	24020001 	li	v0,1
  5c1884:	ae020008 	sw	v0,8(s0)
  5c1888:	0c15c5ff 	jal	0x5717fc
  5c188c:	02202021 	move	a0,s1
  5c1890:	1440001a 	bnez	v0,0x5c18fc
  5c1894:	ae02000c 	sw	v0,12(s0)
  5c1898:	ae500010 	sw	s0,16(s2)
  5c189c:	00008021 	move	s0,zero
  5c18a0:	8fbf0024 	lw	ra,36(sp)
  5c18a4:	02001021 	move	v0,s0
  5c18a8:	8fb20020 	lw	s2,32(sp)
  5c18ac:	8fb1001c 	lw	s1,28(sp)
  5c18b0:	8fb00018 	lw	s0,24(sp)
  5c18b4:	03e00008 	jr	ra
  5c18b8:	27bd0028 	addiu	sp,sp,40
  5c18bc:	3c020075 	lui	v0,0x75
  5c18c0:	8c42cf58 	lw	v0,-12456(v0)
  5c18c4:	1040fff6 	beqz	v0,0x5c18a0
  5c18c8:	2410ffff 	li	s0,-1
  5c18cc:	0c16276a 	jal	0x589da8
  5c18d0:	00000000 	nop
  5c18d4:	5040fff3 	beqzl	v0,0x5c18a4
  5c18d8:	8fbf0024 	lw	ra,36(sp)
  5c18dc:	3c04006d 	lui	a0,0x6d
  5c18e0:	3c05006f 	lui	a1,0x6f
  5c18e4:	2484381c 	addiu	a0,a0,14364
  5c18e8:	24a5f610 	addiu	a1,a1,-2544
  5c18ec:	0c101b74 	jal	0x406dd0
  5c18f0:	24060083 	li	a2,131
  5c18f4:	08170629 	j	0x5c18a4
  5c18f8:	8fbf0024 	lw	ra,36(sp)
  5c18fc:	02202021 	move	a0,s1
  5c1900:	0c15c6bc 	jal	0x571af0
  5c1904:	3045ffff 	andi	a1,v0,0xffff
  5c1908:	1440ffe3 	bnez	v0,0x5c1898
  5c190c:	ae020010 	sw	v0,16(s0)
  5c1910:	3c020075 	lui	v0,0x75
  5c1914:	8c42cf58 	lw	v0,-12456(v0)
  5c1918:	1040000a 	beqz	v0,0x5c1944
  5c191c:	00000000 	nop
  5c1920:	0c16276a 	jal	0x589da8
  5c1924:	00000000 	nop
  5c1928:	10400006 	beqz	v0,0x5c1944
  5c192c:	3c05006f 	lui	a1,0x6f
  5c1930:	3c04006f 	lui	a0,0x6f
  5c1934:	2484f578 	addiu	a0,a0,-2696
  5c1938:	24a5f610 	addiu	a1,a1,-2544
  5c193c:	0c101b74 	jal	0x406dd0
  5c1940:	240600c2 	li	a2,194
  5c1944:	0c101f7c 	jal	0x407df0
  5c1948:	02002021 	move	a0,s0
  5c194c:	08170628 	j	0x5c18a0
  5c1950:	2410ffff 	li	s0,-1
  5c1954:	0c15c5ff 	jal	0x5717fc
  5c1958:	02202021 	move	a0,s1
  5c195c:	0441ffc8 	bgez	v0,0x5c1880
  5c1960:	ae020008 	sw	v0,8(s0)
  5c1964:	08170622 	j	0x5c1888
  5c1968:	00000000 	nop
  5c196c:	8c42cf58 	lw	v0,-12456(v0)
  5c1970:	1040fff4 	beqz	v0,0x5c1944
  5c1974:	00000000 	nop
  5c1978:	0c16276a 	jal	0x589da8
  5c197c:	00000000 	nop
  5c1980:	1040fff0 	beqz	v0,0x5c1944
  5c1984:	3c05006f 	lui	a1,0x6f
  5c1988:	3c04006d 	lui	a0,0x6d
  5c198c:	92070000 	lbu	a3,0(s0)
  5c1990:	24843f08 	addiu	a0,a0,16136
  5c1994:	24a5f610 	addiu	a1,a1,-2544
  5c1998:	2406008c 	li	a2,140
  5c199c:	0c101b74 	jal	0x406dd0
  5c19a0:	00000000 	nop
  5c19a4:	08170651 	j	0x5c1944
  5c19a8:	00000000 	nop
  5c19ac:	8c42cf58 	lw	v0,-12456(v0)
  5c19b0:	1040ffe4 	beqz	v0,0x5c1944
  5c19b4:	00000000 	nop
  5c19b8:	0c16276a 	jal	0x589da8
  5c19bc:	00000000 	nop
  5c19c0:	1040ffe0 	beqz	v0,0x5c1944
  5c19c4:	3c05006f 	lui	a1,0x6f
  5c19c8:	3c04006d 	lui	a0,0x6d
  5c19cc:	92070001 	lbu	a3,1(s0)
  5c19d0:	24843f34 	addiu	a0,a0,16180
  5c19d4:	24a5f610 	addiu	a1,a1,-2544
  5c19d8:	08170667 	j	0x5c199c
  5c19dc:	24060095 	li	a2,149
