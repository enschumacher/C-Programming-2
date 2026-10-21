import java.util.Scanner;

class Kargo {
    private String kargoTakipKodu;
    private double agirlik;
    private int gonderiTipi;

    public Kargo(String kargoTakipKodu, double agirlik, int gonderiTipi) {
        this.kargoTakipKodu = kargoTakipKodu;
        this.agirlik = agirlik;
        this.gonderiTipi = gonderiTipi;
    }

    public void kargoBilgileriniGoster() {
        System.out.println("Kargo Takip Kodu: " + kargoTakipKodu);
        System.out.println("Agirlik: " + agirlik + " kg");
        
        if (gonderiTipi == 1) {
            System.out.println("Gonderi Tipi: Standart");
        } else if (gonderiTipi == 2) {
            System.out.println("Gonderi Tipi: Hizli");
        } else {
            System.out.println("Gonderi Tipi: Gecersiz Tip");
        }
        System.out.println("Gonderi Ucreti: " + kargoUcretHesapla() + " TL");
        System.out.println("-----------------------------------");
    }

    public double kargoUcretHesapla() {
        double ucret = 0.0;

        if (gonderiTipi == 1) {
            ucret = agirlik * 0.5;
        } else if (gonderiTipi == 2) {
            ucret = agirlik * 0.8;
        }

        if (ucret < 20.0) {
            ucret = 20.0;
        }

        return ucret;
    }
}

public class KargoOtomasyon {

    public static void main(String[] args) {
        Scanner klavye = new Scanner(System.in);
        
        Kargo[] kargolar = new Kargo[3];
        
        for (int i = 0; i < 3; i++) {
            System.out.println("=== " + (i + 1) + ". Kargo Bilgilerini Giriniz ===");
            
            System.out.print("Kargo Takip Kodu: ");
            String kod = klavye.nextLine();
            
            System.out.print("Agirlik (kg): ");
            double agirlik = klavye.nextDouble();
            
            System.out.print("Gonderi Tipi (1-Standart, 2-Hizli): ");
            int tip = klavye.nextInt();
            
            klavye.nextLine(); 
            System.out.println();

            kargolar[i] = new Kargo(kod, agirlik, tip);
        }

        System.out.println("\n===================================");
        System.out.println("      TUM GONDERILERIN BILGILERI     ");
        System.out.println("===================================\n");
        
        double toplamGenelUcret = 0.0;

        for (int i = 0; i < 3; i++) {
            kargolar[i].kargoBilgileriniGoster();
            toplamGenelUcret += kargolar[i].kargoUcretHesapla();
        }

        System.out.println(">>> TOPLAM KARGO UCRETI: " + toplamGenelUcret + " TL <<<");
        
        klavye.close();
    }
}