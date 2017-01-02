package org.wwsis.lab1.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class ExampleController {
    //  6.5 wykorzystam istniejący kontroller do "strony głównej"
    @RequestMapping("/")
    public String getForm(Model model) {
        model.addAttribute("formName", "Strona główna - Michał Kawecki");
        model.addAttribute("formStudentUrl", "http://localhost:8080/firstForm");
        model.addAttribute("formAddressUrl", "http://localhost:8080/thirdForm");
        return "index";
    }

    //  4.1. Usuwamy metodę main z poprzednio zaimplementowanego kontrolera
//    public static void main(String[] args) throws Exception {
//        SpringApplication.run(ExampleController.class, args);
//    }

}
