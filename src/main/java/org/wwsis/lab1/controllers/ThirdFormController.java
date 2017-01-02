package org.wwsis.lab1.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.wwsis.lab1.model.Address;

@Controller
public class ThirdFormController {

    @RequestMapping("/thirdForm")
    public String getForm(Model model) {
        model.addAttribute("formName", "Moj formularz z adresem zamieszkania");
        model.addAttribute("formCity", "Miejscowość");
        model.addAttribute("formStreet", "Ulica");
        model.addAttribute("formHouseNumber", "Numer domu");
        model.addAttribute("address", new Address());
        return "thirdForm";
    }

    @PostMapping("/thirdForm")
    public String postForm(Model model, Address address) {
        model.addAttribute("formName", "Twój adres:");
        model.addAttribute("formCity", "Miejscowość");
        model.addAttribute("formStreet", "Ulica");
        model.addAttribute("formHouseNumber", "Numer domu");
        //  --------------
        model.addAttribute("AddressFormCity", address.getCity());
        model.addAttribute("AddressFormStreet", address.getStreet());
        model.addAttribute("AddressFormHouseNumber", address.getHouseNumber());
        return "fourthForm";
    }
}
