package org.wwsis.lab1.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.wwsis.lab1.model.Student;

import java.util.Date;

@Controller
public class FirstFormController {

    //  6.1 Wyświetl na firstForm aktualną datę i godzinę pobraną z serwera
    private Date currentDate;

    //  4.3. Do pakietu org.wwsis.lab1.controllers dodajemy kontroler dla naszego formularza
//    @RequestMapping("/firstForm")
//    public String getForm() {
//        return "firstForm";
//    }

    @RequestMapping("/firstForm")
    public String getForm(Model model) {
        model.addAttribute("formName", "Moj formularz studenta");
        model.addAttribute("formFirstName", "Imię");
        model.addAttribute("formLastName", "Nazwisko");
        model.addAttribute("formAge", "Wiek");
        model.addAttribute("formAddress", "Adres");
        model.addAttribute("formEmail", "E-mail");
        model.addAttribute("student", new Student());
        return "firstForm";
    }

    @PostMapping("/firstForm")
    public String postForm(Model model, Student student) {
        //  6.3 W przypadku podania przez użytkownika na formularzu ujemnej wartości wieku, wród na ten
        //      formularz z tymi samymi danymi oraz wyświetl informację o błędnej wartości
        if(student.getAge() < 0) {
            model.addAttribute("formName", "Moj formularz");
            model.addAttribute("formFirstName", "Imię");
            model.addAttribute("formLastName", "Nazwisko");
            model.addAttribute("formAge", "Wiek");
            model.addAttribute("formAddress", "Adres");
            model.addAttribute("formEmail", "E-mail");
            model.addAttribute("error", "Uwaga! Wiek nie może być ujemny!");
            return "firstForm";
        }
        currentDate = new Date();
        model.addAttribute("studentFirstName", student.getFirstName());
        model.addAttribute("studentLastName", student.getLastName());
        model.addAttribute("studentAge", student.getAge());
        model.addAttribute("studentAddress", student.getAddress());
        model.addAttribute("studentEmail", student.getEmail());
        model.addAttribute("currentDate", this.getCurrentDate());
        return "secondForm";
    }

    public Date getCurrentDate() {
        return currentDate;
    }

    public void setCurrentDate(Date currentDate) {
        this.currentDate = currentDate;
    }
}
