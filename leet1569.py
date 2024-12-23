class Solution:
    def numOfWays(self, nums):
        MOD = 10**9 + 7

        def combinacoes(n, k):
            if k > n:
                return 0
            if k == 0 or k == n:
                return 1
            numerador = 1
            denominador = 1
            for i in range(k):
                numerador *= (n - i)
                denominador *= (i + 1)
            return numerador // denominador

        def contar_caminhos(subarvore):
            if len(subarvore) <= 2:
                return 1

            raiz = subarvore[0]
            esquerda = [x for x in subarvore if x < raiz]
            direita = [x for x in subarvore if x > raiz]

            caminhos_esquerda = contar_caminhos(esquerda)
            caminhos_direita = contar_caminhos(direita)

            return combinacoes(len(esquerda) + len(direita), len(esquerda)) * caminhos_esquerda * caminhos_direita % MOD

        return (contar_caminhos(nums) - 1) % MOD