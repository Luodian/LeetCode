from typing import List


class Solution:
	def uniqueOccurrences(self, arr: List[int]) -> bool:
		cnt = {x: 0 for x in arr}
		for item in arr:
			cnt[item] += 1
		ans = True
		st = set()
		for item in cnt:
			st.add(cnt[item])
		
		if len(st) != len(cnt):
			return False
		else:
			return True
	
	def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
		import numpy as np
		df_arr = []
		for i in range(len(s)):
			df_arr.append(abs(ord(s[i]) - ord(t[i])))
		
		print(df_arr)
		N = len(df_arr)
		st = 0
		ed = 0
		current_cost = 0
		ans = 0
		while ed < N:
			current_cost += df_arr[ed]
			ed += 1
			while current_cost > maxCost and st < ed:
				current_cost -= df_arr[st]
				st += 1
			ans = max(ans, ed - st)
		
		return ans


sample_func = Solution()
# s = "abcd"
# t = "cdef"
# cost = 3
# s = "abcd"
# t = "acde"
# cost = 0
# s = "abcd"
# t = "bcdf"
# cost = 3
# s = \
# 	"iasqmoizrzxvfdiohtqmckhcwjqowztsxioesmcbijninqllhkyoqbxjupzggzskckmnebopcgeiybbdpxpbdyjlaqedftffxdlnztgtuwxhfhnebujgetjovjozprekmzoxsejgrgeswdlkiptpoiavjvyxjduqtnfwkbtuiumwvmwqdbgvyubulsmwfdhofssngousnrypprfufyihswuhlvxaoirysjqigfuczvltcowshjvlsxcjnqcauyvcvlcdxtodinnzylbdqfxmjvyhmxerczazpnczptrhdeiiqachungawhyytqxadbkmofnaagyouhiaznzvddsfbvnzwgrtcqhmkhdlwbcoflorfakhabktruimxzasabbbmrddjskxcseyuzxlxdrxyspomhmhbbkgqbwnsmudebbcskseemymfwsdddbbwqrylgqkcqrecgibaecoozwogbepwdwlbrfkqemzyfyvzavxdedhovmmfqkmakgzpfdmcitrgifdrdixdimxiuywngqkvvaqlfrcbszhcbagtfbhrgvbvooxorhiutxonaxnmgjkksutvdhrcikqjwtpfspqpgoxnawqhaisyxycjyyrknfudpnrrfbkxzhkhpqwhwbeixopgtoxydkjylmtrtudfleowmaxxxgefpndhglzjuehaeuizysazzjtkorjcffloexusxtkfvaiwmvdfdxhnmsgzryddlcnnziczfwuwvcshivkzgjjppxdjjjspxwbztouepaejyqzgvmajyvbvtqgntyccjwtswehhvdavftuyasntyugnsprlmgbhdlllwkejcupyzdialljsqvnmivnxizthtfxvchkqyrjxlhmezsgzvevkzgiiesfugdyormrxppmeomxbnphlccawlliwmerejfddzjyuauxzqufevdagvenvijxvhquhlfwnxwhlsajjveqsgzergaitsslsiummxxamduf"
# t = \
# 	"dqbtxqabwhcahdvhcvirvatalwvehnvcrihbrewlztdvvxdsjtpvjafgjsqwuyitbguffgntryoqxjymvhsscgmankssmmqhrzoapiojracsyljsdbgxvqabnyifozlihxudycbhtmnhobqksbnhvvgltvouqbylpnpefpdrdmjvwodeccabbanxhennyvqigldjfqewakravmlitcnzbrkeceizleqsbqnzkgabghwyrbhghmkvfpjposszywjpyjbzuoozjrsmxaeiezpqhbophqxwhbnynmoslrcdupncefdlylaljunszmcajlevechqevmovwcrimatgowspfmgmgcuvqblckyglvsxvhymhugrsoseqobghmvtnqlfaqipiwsvuwzpzguxxpgiviybomrypnkgjqcvfrffmtfwdimfwcucjcjcplwebgbfsolbhnuzlupoerzzaukqgnaaryimdslcjbzwloaklkiupdxcnkqhonskawwsxjlfzzregxhwuvhlupsevfhbfeabhacxuhyigaqxkbrmjxfjvivxumzosrzcweqycnbvewxszdcnxlcrbnfzmgoclwioytpnsnmdpujfptesconvtqhxjsvutrafqevafwrzgljgejewuinzdpofabobaxstzihioqhamfxmplpnunpzufwlpgldbvuiezwwyuctkynazzbdxcwnhdxauicfggmmisnldskmwgieenxyjcmdzgbrxlwflngtzwkldtzjpjfmumbfszhvrqprbpwjtgkmidjrzuoojnlnyfsgxdvidxjblteitlrwnqvcrjplkwntxwidiippmaqwyglpurpklzulcplndjstamosqfzjdntnpxmgabzicvvfzozutltydotuvvlwoxpktsdhturcnucsdvkowkarcmgbsgrgdkfclwshzkzzcgpngtbkffrsmieijbawwryptwlybjytubbrzxzdgqqqlxvt"
# cost = 4713
# s = "abcd"
# t = "cdef"
# cost = 1
# s = "pxezla"
# t = "loewbi"
# cost = 25
# s = "anryddgaqpjdw"
# t = "zjhotgdlmadcf"
# cost = 5
s = "ujteygggjwxnfl"
t = "nstsenrzttikoy"
cost = 43
ans = sample_func.equalSubstring(s, t, cost)
print(ans)
