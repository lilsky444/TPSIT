class AlphaBot(object):
    
    def __init__(self):
        self.avanti = "Vai avanti"
        self.indietro = "Vai indietro"
        self.sinistra = "Vai a sinistra"
        self.destra = 'Vai a destra'


    def forward(self):
        return self.avanti        

    def backward(self):
        return self.indietro

    def left(self, speed=30):
        return self.sinistra

    def right(self, speed=30):
        return self.destra